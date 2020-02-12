/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:13:42 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/12 16:12:15 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

void		set_qoute(int *qoute, int i, char *tmp)
{
	(*qoute) = ((*qoute) == 1) ? 0 : 1;
	if (g_to_skip == 1 && tmp[i - 1] == '\\')
	{
		(*qoute) = 0;
		g_to_skip = 0;
	}
}

void		init_parse_var(int *qoute, int *is_cmd)
{
	g_start = 0;
	*is_cmd = 0;
	*qoute = 0;
}

int			skip_or_fin(char c)
{
	if (c == '\\')
		g_to_skip = (g_to_skip == 0) ? 1 : 0;
	if (c == '\0')
		return (1);
	return (0);
}

t_command	*parse(char *line, t_command *cmd)
{
	int		i;
	char	*tmp;
	int		is_cmd;
	int		qoute;

	i = 0;
	init_parse_var(&qoute, &is_cmd);
	tmp = ft_strtrim(line, " \t");
	while (tmp[i] != '\0')
	{
		if (ft_strchr(" \t", tmp[i]) != NULL && qoute == 0)
			cmd = putspacecmd(&i, &is_cmd, tmp, cmd);
		if (tmp[i] == '\'' || tmp[i] == '\"')
			set_qoute(&qoute, i, tmp);
		if ((tmp[i] == '|' || tmp[i] == '<' || tmp[i] == ';') && qoute == 0)
			cmd = pipe_rin_semicol(&i, &is_cmd, tmp, cmd);
		else if (tmp[i] == '>' && qoute == 0)
			cmd = rediriction_out(&i, &is_cmd, tmp, cmd);
		if (skip_or_fin(tmp[i]) == 1)
			break ;
		i++;
	}
	cmd = putspacecmd(&i, &is_cmd, tmp, cmd);
	free(tmp);
	return (cmd);
}
