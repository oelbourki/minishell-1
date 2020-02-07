/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 21:55:37 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/06 18:02:11 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		is_cmd(char *sem)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (!ft_strcmp(sem, g_commands[i]))
			return (1);
		i++;
	}
	return (0);
}

int		is_string(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isalpha(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	init_t_vars(t_vars *var)
{
	var->n = 0;
	var->m = 0;
	var->i = 0;
	var->j = 0;
	var->first = 0;
	var->input = 0;
	var->semi = NULL;
	var->pipe = NULL;
	var->arg = NULL;
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_print(char *s)
{
	ft_printf("%s", s);
	g_status = 1;
	return (0);
}
