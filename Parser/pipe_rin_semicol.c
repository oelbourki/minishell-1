/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_rin_semicol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:46:48 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/07 11:45:56 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*pipe_token(char *t, int *is_cmd, char *tmp, int *i)
{
	int k;

	k = 1;
	if (g_to_skip == 0)
		return (ft_lstnew_command(t, PIPE));
	else
	{
		*is_cmd = 1;
		while (tmp[*i] != '\0' && ft_strchr(" \t", tmp[*i]) == NULL)
			if (ft_strchr(" \t", tmp[++(*i)]) == NULL)
				t[k++] = tmp[(*i)];
		t[k] = '\0';
		(*i) -= 1;
		printf("tptpt = #%s#\n", t);
		return (ft_lstnew_command(t, STRING));
	}
}

t_command	*redin_token(char *t, int *is_cmd, char *tmp, int *i)
{
	int		k;

	k = 1;
	if (g_to_skip == 0)
	{
		*is_cmd = 1;
		return (ft_lstnew_command(t, REDIN));
	}
	else
	{
		while (tmp[*i] != ' ' && tmp[*i] != '\0' && tmp[*i] != '\t')
			if (ft_strchr(" \t", tmp[++(*i)]) == NULL)
				t[k++] = tmp[(*i)];
		t[k] = '\0';
		(*i) -= 1;
		return (ft_lstnew_command(t, STRING));
	}
}

t_command	*semicol_token(char *t, int *is_cmd, char *tmp, int *i)
{
	int		k;

	k = 1;
	if (g_to_skip == 0)
		return (ft_lstnew_command(t, SEMICOL));
	else
	{
		*is_cmd = 1;
		while (tmp[*i] != ' ' && tmp[*i] != '\0' && tmp[*i] != '\t')
			if (ft_strchr(" \t", tmp[++(*i)]) == NULL)
				t[k++] = tmp[(*i)];
		t[k] = '\0';
		(*i) -= 1;
		return (ft_lstnew_command(t, STRING));
	}
}

t_command	*pipe_rin_semicol(int *i, int *is_cmd, char *tmp, t_command *cmd)
{
	t_command	*node;
	char		t[4096];

	t[0] = tmp[*i];
	t[1] = '\0';
	cmd = putspacecmd(i, is_cmd, tmp, cmd);
	*is_cmd = 0;
	if (tmp[*i] == '|')
		node = pipe_token(t, is_cmd, tmp, i);
	else if (tmp[*i] == '<')
		node = redin_token(t, is_cmd, tmp, i);
	else
		node = semicol_token(t, is_cmd, tmp, i);
	ft_lstadd_back_command(&cmd, node);
	if (g_to_skip == 1)
		g_to_skip = 0;
	g_start = *i + 1;
	return (cmd);
}
