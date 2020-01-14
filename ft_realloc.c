/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 22:03:55 by oel-bour          #+#    #+#             */
/*   Updated: 2019/12/05 22:03:57 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	*ft_realloc(void *ptr, size_t old, size_t size)
{
	char	*p;

	if (size == 0)
		return (ptr);
	p = (char *)malloc(size);
	if (p == NULL)
		return (ptr);
	if (ptr == NULL)
		return (p);
	ft_memcpy(p, ptr, old);
	ft_free(ptr);
	return (p);
}
