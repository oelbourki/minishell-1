/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:05:57 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/13 19:06:00 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *counter;

	if (lst == NULL)
		return (NULL);
	counter = lst;
	while (counter->next)
	{
		counter = counter->next;
	}
	return (counter);
}
