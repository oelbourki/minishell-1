/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:58:38 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/13 18:58:44 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *counter;

	if (*alst == NULL)
	{
		*alst = new;
	}
	else
	{
		counter = *alst;
		while (counter->next)
		{
			counter = (counter)->next;
		}
		(counter)->next = new;
	}
}
