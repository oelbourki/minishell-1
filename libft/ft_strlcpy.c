/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:24:30 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/19 21:30:16 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (len_src < size - 1)
	{
		while (i++ < len_src)
			dst[i - 1] = src[i - 1];
		dst[i - 1] = '\0';
	}
	else
	{
		while (i++ < size - 1)
			dst[i - 1] = src[i - 1];
		dst[i - 1] = '\0';
	}
	return (len_src);
}
