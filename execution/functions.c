/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:52:00 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/07 18:34:55 by ibaali           ###   ########.fr       */
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
		return ;
	}
	while (counter->next)
	{
		if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0 &&
		ft_free(&counter->value) && (counter->value = ft_strdup(s[1])))
			return ;
		counter = counter->next;
	}
	if (!help_push(&counter, s))
		counter->next = data;
}
