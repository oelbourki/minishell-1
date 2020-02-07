/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:35:26 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/06 18:02:11 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	help_export(char **arg)
{
	t_env	*data;
	char	**s;

	data = (t_env *)malloc(sizeof(t_env));
	s = ft_split(arg[1], '=');
	data->variable = ft_strdup(s[0]);
	data->value = ft_strdup(s[1]);
	data->next = NULL;
	push_back_ex(&g_environt, data, s);
	ft_free_star(s);
}

int		export(char **arg)
{
	char *s;

	s = "bash: export: `=': not a valid identifier\n";
	if (arg[1] == NULL)
		env_declarex(g_environt);
	else
	{
		if (arg[1][0] == '=')
		{
			write(1, s, strlen(s));
			g_status = 1;
			return (1);
		}
		else if (ft_strchr(arg[1], '=') == NULL)
			return (1);
		else
			help_export(arg);
		return (0);
	}
	return (1);
}
