/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:08:17 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/06 18:02:11 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*var(char *s)
{
	int		i;
	t_env	*tmp;
	t_env	*cmd;
	char	*var;

	cmd = g_environt;
	if (s == NULL)
		return (0);
	i = 0;
	while (cmd)
	{
		if (ft_strncmp(s, cmd->variable, ft_strlen(s)) == 0)
			return (ft_strdup((cmd->value)));
		cmd = cmd->next;
	}
	return (0);
}

int			env_var(t_env *ls)
{
	t_env	*tmp;

	if (ls == NULL)
		return (0);
	tmp = ls;
	while (tmp != NULL)
	{
		printf("%s=%s\n", tmp->variable, tmp->value);
		tmp = tmp->next;
	}
	return (1);
}
