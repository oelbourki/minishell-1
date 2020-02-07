/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:02:21 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 19:02:26 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*move2(unsigned char *dst,
unsigned char *src,
unsigned char c, size_t len)
{
	size_t i;

	if (dst == NULL)
		dst[0] = 'a';
	i = 0;
	while (src[i] != '\0' && i < len && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == c)
	{
		dst[i] = src[i];
		return (dst + i + 1);
	}
	return (NULL);
}

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		num;
	unsigned char		*s;

	if (n == 0)
		return (NULL);
	num = (unsigned char)c;
	s = (unsigned char*)src;
	return (move2(dst, s, num, n));
}
