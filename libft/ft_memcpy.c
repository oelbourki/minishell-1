/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:33:35 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/20 21:21:51 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmp_dst;
	char	*tmp_src;

	i = 0;
	tmp_dst = (char*)dst;
	tmp_src = (char*)src;
	if (dst == src)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return (dst);
}
