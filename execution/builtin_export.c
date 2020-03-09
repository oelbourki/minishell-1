/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:35:26 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 10:35:13 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	help_export(char *arg)
{
	t_env	*data;
	char	**s;

	data = NULL;
	s = ft_split(arg, '=');
	push_back_ex(&g_environt, data, s);
	ft_free_star(s);
}

int		export_help(char **arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i][0] == '=')
		{
			ft_print("bash: export: `=': not a valid identifier\n");
			return (ft_print("bash: export: `=': not a valid identifier\n"));
		}
		else if (ft_strchr(arg[i], '=') == NULL)
		{
			if (!is_string(arg[i]))
			{
				ft_print("bash: export: `%s': not a valid identifier\n");
			}
			return (1);
		}
		else
			help_export(arg[i]);
		i++;
	}
	return (0);
}

int		export(char **arg)
{
	int		i;

	i = 0;
	g_s = "bash: export: `=': not a valid identifier\n";
	if (arg[1] == NULL)
		env_declarex(g_environt);
	else
	{
		while (arg[++i])
		{
			if (arg[i][0] == '=')
				return (ft_print(g_s));
			else if (ft_strchr(arg[i], '=') == NULL)
			{
				g_s = "bash: export: `%s': not a valid identifier\n";
				if (!is_string(arg[i]))
					ft_printf(g_s, arg[i]);
				return (1);
			}
			else
				help_export(arg[i]);
		}
		return (0);
	}
	return (1);
}
