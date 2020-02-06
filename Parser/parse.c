/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:13:42 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/06 12:33:47 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*putspacecmd(int *fin, int *is_cmd, char *tmp, t_command *cmd)
{
	t_command	*node;
	char		*a_free;
	char		*trim;

	trim = ft_substr(tmp, g_start, *fin - g_start);
	a_free = ft_strtrim(trim, " \t");
	free(trim);
	while (tmp[g_start] == ' ' || tmp[g_start] == '\t')
		(g_start) += 1;
	if (ft_strchr("|;<>", tmp[g_start]) == NULL && g_start < *fin)
	{
		if (*is_cmd == 0)
			node = ft_lstnew_command(a_free, COMMAND);
		else
			node = ft_lstnew_command(a_free, STRING);
		ft_lstadd_back_command(&cmd, node);
	}
	if (g_start < *fin)
		*is_cmd = 1;
	g_start = *fin;
	while (tmp[*fin] == ' ' || tmp[*fin] == '\t')
		(*fin) += 1;
	free(a_free);
	return (cmd);
}

t_command	*parse(char *line, t_command *cmd)
{
	int		i;
	char	*tmp;
	int		is_cmd;
	int		qoute;

	i = 0;
	g_start = 0;
	is_cmd = 0;
	qoute = 0;
	tmp = ft_strtrim(line, " \t");
	while (tmp[i] != '\0')
	{
		if (ft_strchr(" \t", tmp[i]) != NULL && qoute == 0)
			cmd = putspacecmd(&i, &is_cmd, tmp, cmd);
		if (tmp[i] == '\'' || tmp[i] == '\"')
			qoute = (qoute == 1) ? 0 : 1;
		if ((tmp[i] == '|' || tmp[i] == '<' || tmp[i] == ';') && qoute == 0)
			cmd = pipe_rin_semicol(&i, &is_cmd, tmp, cmd);
		else if (tmp[i] == '>' && qoute == 0)
			cmd = rediriction_out(&i, &is_cmd, tmp, cmd);
		if (tmp[i] == '\\')
			g_to_skip = (g_to_skip == 0) ? 1 : 0;
		i++;
	}
	cmd = putspacecmd(&i, &is_cmd, tmp, cmd);
	free(tmp);
	return (cmd);
}

void	print_command(t_command *g_command)
{
	while (g_command != NULL)
	{
		ft_printf("\nnode = [%s] index = ", g_command->str);
		if (g_command->what == DOUBLEREDOUT)
			ft_printf("DOUBLEREDOUT");
		else if (g_command->what == REDIN)
			ft_printf("REDIN\n");
		else if (g_command->what == REDOUT)
			ft_printf("REDOUT\n");
		else if (g_command->what == SEMICOL)
			ft_printf("SEMICOL\n");
		else if (g_command->what == COMMAND)
			ft_printf("COMMAND\n");
		else if (g_command->what == STRING)
			ft_printf("STRING\n");
		else if (g_command->what == PIPE)
			ft_printf("PIPE\n");
		g_command = g_command->next;
	}
	ft_printf("\n");
}
