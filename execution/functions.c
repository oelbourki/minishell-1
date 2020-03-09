/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:52:00 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 10:57:59 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free_node(t_env **node)
{
	t_env *counter;

	counter = *node;
	ft_free(&counter->value);
	ft_free(&counter->variable);
}

int		help_push(t_env **head, char **s)
{
	t_env *counter;

	counter = *head;
	if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0)
	{
		ft_free_node(&counter);
		counter->value = ft_strdup(s[1]);
		counter->variable = ft_strdup(s[0]);
		return (1);
	}
	return (0);
}

t_env	*help_push_1(t_env **head, char **s)
{
	t_env *counter;

	counter = *head;
	if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0)
	{
		ft_free_node(&counter);
		counter->value = ft_strdup(s[1]);
		counter->variable = ft_strdup(s[0]);
		return (NULL);
	}
	while (counter->next)
	{
		if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0)
		{
			ft_free_node(&counter);
			counter->value = ft_strdup(s[1]);
			counter->variable = ft_strdup(s[0]);
			return (NULL);
		}
		counter = counter->next;
	}
	return (counter);
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
	if (((counter = help_push_1(head, s)) == NULL))
		return ;
	if (!help_push(&counter, s))
	{
		data = (t_env *)malloc(sizeof(t_env));
		data->variable = ft_strdup(s[0]);
		data->value = ft_strdup(s[1]);
		data->next = NULL;
		counter->next = data;
	}
}
