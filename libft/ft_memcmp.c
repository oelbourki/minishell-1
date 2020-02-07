/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:08:05 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 19:08:07 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strncmp1(unsigned char *s1, unsigned char *s2, size_t size)
{
	size_t i;

	if (size == 0)
		return (0);
	i = 0;
	while ((i < size))
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *h1;
	unsigned char *h2;

	h1 = (unsigned char*)s1;
	h2 = (unsigned char*)s2;
	return (ft_strncmp1(h1, h2, n));
}
