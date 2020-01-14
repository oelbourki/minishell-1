/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:43:28 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/13 02:23:39 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	index;

	index = 0;
	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	while (*dst != '\0' && index < size)
	{
		dst++;
		index++;
	}
	if (index == size)
		return (index + len_src);
	while (*src != '\0')
	{
		if (index++ < size - 1)
			*dst++ = *src;
		src++;
	}
	*dst = '\0';
	return (len_dst + len_src);
}
