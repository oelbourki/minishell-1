/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:02:48 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/13 19:02:51 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	int				i;
	t_list			*counter;
	t_list			*tmp;

	if (*lst && del)
	{
		i = 0;
		counter = *lst;
		while (counter)
		{
			tmp = counter;
			(*del)(counter->content);
			counter = counter->next;
			free(tmp);
		}
		*lst = NULL;
	}
}
