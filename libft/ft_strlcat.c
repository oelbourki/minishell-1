/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:20:43 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 19:20:47 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	while (dst[j] != '\0')
		j++;
	if (n == 0 || n == j)
		return (dst);
	i = 0;
	while ((src[i] != '\0') && (i < n - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		x;

	x = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (x);
	i = size - ft_strlen(dst);
	j = ft_strlen(dst);
	if (size > j)
	{
		ft_strncat(dst, src, i);
		return (x + j);
	}
	else
	{
		return (x + size);
	}
}
