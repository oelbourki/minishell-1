/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:52:00 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:03:18 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		help_push(t_env **head, char **s)
{
	t_env *counter;

	counter = *head;
	if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0)
	{
		ft_free(&counter->value);
		counter->value = ft_strdup(s[1]);
		ft_free(&counter->variable);
		counter->variable = ft_strdup(s[0]);
		return (1);
	}
	return (0);
}

void	push_back_ex(t_env **head, t_env *data, char **s)
{
	t_env *counter;

	counter = *head;
	if (counter == NULL)
	{
		*head = data;
		return ;
	}
	if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0)
	{
		ft_free(&counter->value);
		counter->value = ft_strdup(s[1]);
		ft_free(&counter->variable);
		counter->variable = ft_strdup(s[0]);
		return ;
	}
	while (counter->next)
	{
		if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0 &&
		ft_free(&counter->value) && (counter->value = ft_strdup(s[1])))
		{
			ft_free(&counter->variable);
			counter->variable = ft_strdup(s[0]);
			return ;
		}
		counter = counter->next;
	}
	if (!help_push(&counter, s))
	{
		data = (t_env *)malloc(sizeof(t_env));
		data->variable = ft_strdup(s[0]);
		data->value = ft_strdup(s[1]);
		data->next = NULL;
		counter->next = data;
	}
}
