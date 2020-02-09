/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:26:46 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/09 23:13:00 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			red_error(t_command *tmp)
{
	if ((tmp->what == REDIN || tmp->what == REDOUT || tmp->what == DOUBLEREDOUT)
	&& (tmp->next == NULL || tmp->next->what != STRING))
	{
		ft_putstr_fd("bash: syntax error near unexpected token `newline'\n", 1);
		return (-1);
	}
	return (0);
}

t_command	*parse_error(t_command **cmd)
{
	t_command	*tmp;
	t_command	*prev;

	tmp = *cmd;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->what == STRING && tmp->next->what ==
		STRING && ft_strchr("|;<>", tmp->next->str[0]) != NULL)
		{
			tmp->str = ft_strjoin(tmp->str, tmp->next->str);
			tmp->next->str[0] = '\0';
			prev = tmp->next;
			tmp->next = tmp->next->next;
			free(prev->str);
			free(prev);
		}
		if (red_error(tmp) == -1)
		{
			ft_lstclear_command(cmd);
			*cmd = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	return (*cmd);
}
