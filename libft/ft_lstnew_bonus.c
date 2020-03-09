/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:08:27 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/13 19:08:31 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *tmp;

	tmp = NULL;
	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp == NULL)
	{
		return (NULL);
	}
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}
