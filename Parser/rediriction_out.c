/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rediriction_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:19:20 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/07 18:34:55 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_command	*doubleoutred(int *i, char *t)
{
	t[1] = '>';
	t[2] = '\0';
	*i += 1;
	g_start = *i + 1;
	if (g_to_skip == 0)
		return (ft_lstnew_command(t, DOUBLEREDOUT));
	else
		return (ft_lstnew_command(t, REDOUT));
}

t_command	*simpleoutred(char *t, char *tmp, int *i)
{
	int		k;

	k = 1;
	if (g_to_skip == 0)
		return (ft_lstnew_command(t, REDOUT));
	else
	{
		if (g_to_skip == 1)
			g_to_skip = 0;
		while (tmp[*i] != ' ' && tmp[*i] != '\0' && tmp[*i] != '\t')
			if (ft_strchr(" \t", tmp[++(*i)]) == NULL)
				t[k++] = tmp[(*i)];
		t[k] = '\0';
		(*i) -= 1;
		return (ft_lstnew_command(t, STRING));
	}
}

t_command	*rediriction_out(int *i, int *is_cmd, char *tmp, t_command *cmd)
{
	t_command	*node;
	char		t[4096];

	t[0] = '>';
	t[1] = '\0';
	cmd = putspacecmd(i, is_cmd, tmp, cmd);
	if (tmp[*i + 1] == '>')
		node = doubleoutred(i, t);
	else
		node = simpleoutred(t, tmp, i);
	ft_lstadd_back_command(&cmd, node);
	g_start = *i + 1;
	return (cmd);
}
