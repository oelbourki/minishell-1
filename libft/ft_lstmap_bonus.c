/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:28:35 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/19 22:42:14 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*n_lst;

	if (lst == NULL)
		return (NULL);
	n_lst = (t_list*)malloc(sizeof(t_list));
	if (n_lst == NULL)
		return (NULL);
	n_lst->content = f(lst->content);
	n_lst->next = NULL;
	lst = lst->next;
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, new);
		lst = lst->next;
	}
	return (n_lst);
}
