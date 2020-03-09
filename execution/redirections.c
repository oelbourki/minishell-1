/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:23:32 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 15:21:52 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		cmd(t_command **head)
{
	g_counter = *head;
	if (g_counter != NULL && g_counter->what == STRING)
	{
		g_counter->what = COMMAND;
		help_convert1(g_counter);
		return (1);
	}
	else
		return (0);
}

int		help_do_somein(void)
{
	if (g_counter->next->what != REDIN && g_counter->next->what != REDOUT &&
	g_counter->next->what != DOUBLEREDOUT && g_counter->next->str != NULL)
	{
		g_in_fd = open(g_counter->next->str, O_RDONLY, 0);
		g_counter->next->what = STRING;
		if (g_counter->next->next != NULL &&
		g_counter->next->next->what == REDIN)
			close(g_in_fd);
		else if (g_in_fd < 0)
			return (error(g_counter->next->str));
	}
	else if (g_counter->next->what == REDIN)
		ft_print("bash: syntax error near unexpected token `<'\n");
	else
		return (-1);
	return (0);
}

int		do_somein(t_command **head)
{
	g_counter = *head;
	while (g_counter != NULL && g_counter->what == REDIN)
	{
		if (g_counter->next == NULL)
		{
			ft_print("bash: syntax error near unexpected token `newline\'\n");
			return (-1);
		}
		if (help_do_somein() == -1)
			return (-1);
		g_counter = g_counter->next->next;
	}
	if (g_counter != NULL && (g_counter->what == REDOUT ||
	g_counter->what == DOUBLEREDOUT) && do_someout(&g_counter))
		return (1);
	g_mul_redin = 1;
	return (cmd(&g_counter));
}

int		help_do_someout(void)
{
	if (g_counter->next->what != REDOUT && g_counter->next->what !=
	DOUBLEREDOUT && g_counter->next->str != NULL)
	{
		if (g_counter->what == REDOUT)
			g_out_fd = open(g_counter->next->str,
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			g_out_fd = open(g_counter->next->str, O_RDWR
			| (O_APPEND | O_CREAT), S_IRWXU);
		g_counter->next->what = STRING;
		if (g_counter->next->next != NULL && (g_counter->next->next->what
		== REDOUT || g_counter->next->next->what == DOUBLEREDOUT))
			close(g_out_fd);
		else if (g_in_fd < 0)
			return (error(g_counter->next->str));
	}
	else if (g_counter->next->what == REDOUT)
		ft_print("bash: syntax error near unexpected token `>'\n");
	else if (g_counter->next->what == DOUBLEREDOUT)
		ft_print("bash: syntax error near unexpected token `>>'\n");
	else
		return (-1);
	return (0);
}

int		do_someout(t_command **head)
{
	g_counter = *head;
	while (g_counter != NULL && (g_counter->what == REDOUT ||
	g_counter->what == DOUBLEREDOUT))
	{
		if (g_counter->next == NULL)
		{
			ft_print("bash: syntax error near unexpected token `newline\'\n");
			return (-1);
		}
		if (help_do_someout() == -1)
			return (-1);
		g_counter = g_counter->next->next;
	}
	if (g_counter != NULL && g_counter->what == REDIN && do_somein(&g_counter))
		return (1);
	g_multi_redout = 1;
	return (cmd(&g_counter));
}
