/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:53:04 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/19 21:27:24 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	i = 0;
	tmp_dst = (unsigned char*)dst;
	tmp_src = (unsigned char*)src;
	if (n == 0)
		return (NULL);
	while (i < n && tmp_src[i] != (unsigned char)c)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	if (tmp_src[i] == (unsigned char)c)
	{
		tmp_dst[i] = tmp_src[i];
		return (dst + i + 1);
	}
	return (NULL);
}
