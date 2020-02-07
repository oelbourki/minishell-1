/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:07:13 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 19:07:15 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*h;
	unsigned char		x;
	size_t				i;

	if (n == 0)
		return (NULL);
	h = (unsigned char*)s;
	x = (unsigned char)c;
	i = 0;
	while (h[i] != '\0' && i < n)
	{
		if (h[i] == x)
			return (void*)(s + i);
		i++;
	}
	if (x == '\0')
		return ((void*)(s + i));
	return (NULL);
}
