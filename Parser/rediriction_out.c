/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rediriction_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:19:20 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/06 12:25:39 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

t_command	*simpleoutred(char *t)
{
	if (g_to_skip == 0)
		return (ft_lstnew_command(t, REDOUT));
	else
	{
		if (g_to_skip == 1)
			g_to_skip = 0;
		return (ft_lstnew_command(t, STRING));
	}
}

t_command	*rediriction_out(int *i, int *is_cmd, char *tmp, t_command *cmd)
{
	t_command	*node;
	char		t[3];

	t[0] = '>';
	t[1] = '\0';
	cmd = putspacecmd(i, is_cmd, tmp, cmd);
	g_start = *i + 1;
	if (tmp[*i + 1] == '>')
		node = doubleoutred(i, t);
	else
		node = simpleoutred(t);
	ft_lstadd_back_command(&cmd, node);
	return (cmd);
}
