/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:33:39 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 16:11:11 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	env(t_env *ls)
{
	t_env *tmp;

	if (ls == NULL)
		return (0);
	tmp = ls;
	while (tmp != NULL)
	{
		ft_printf("%s=%s\n", tmp->variable, tmp->value);
		tmp = tmp->next;
	}
	g_status = 0;
	return (1);
}

int	env_declarex(t_env *ls)
{
	t_env *tmp;

	if (ls == NULL)
		return (0);
	tmp = ls;
	while (tmp != NULL)
	{
		ft_printf("declare -x %s=%s\n", tmp->variable, tmp->value);
		tmp = tmp->next;
	}
	g_status = 0;
	return (1);
}
