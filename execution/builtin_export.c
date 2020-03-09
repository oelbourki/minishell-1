/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:35:26 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/08 11:04:42 by oel-bour         ###   ########.fr       */
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

int		export(char **arg)
{
	char *s;
	int		i;

	i = 1;
	s = "bash: export: `=': not a valid identifier\n";
	if (arg[1] == NULL)
		env_declarex(g_environt);
	else
	{
		while (arg[i])
		{
			if (arg[i][0] == '=')
			{
				write(1, s, strlen(s));
				g_status = 1;
				return (1);
			}
			else if (ft_strchr(arg[i], '=') == NULL)
			{
				if (!is_string(arg[i]))
				{
					ft_printf("bash: export: `%s': not a valid identifier\n",arg[i]);
				}
				return (1);
			}
			else
				help_export(arg[i]);
			i++;
		}
		
		// if (arg[1][0] == '=')
		// {
		// 	write(1, s, strlen(s));
		// 	g_status = 1;
		// 	return (1);
		// }
		// else if (ft_strchr(arg[1], '=') == NULL)
		// 	return (1);
		// else
		// 	help_export(arg);
		return (0);
	}
	return (1);
}
