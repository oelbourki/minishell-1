/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:20:54 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/13 19:20:56 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	size_t		size;
	t_list		*counter1;
	t_list		*head;
	t_list		*tmp;

	head = NULL;
	if (lst == NULL)
		return (NULL);
	size = ft_lstsize(lst);
	counter1 = lst;
	while (counter1)
	{
		tmp = ft_lstnew(((*f)(counter1->content)));
		if (tmp == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, tmp);
		counter1 = counter1->next;
	}
	return (head);
}
