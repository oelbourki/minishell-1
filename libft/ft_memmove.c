/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:59:48 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/20 21:22:18 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_src;
	char		*tmp_dst;
	size_t		i;

	i = 0;
	tmp_src = (char*)src;
	tmp_dst = (char*)dst;
	if (len == 0 || (dst == NULL && src == NULL))
		return (dst);
	if (dst <= src)
		ft_memcpy((void*)tmp_dst, (void*)tmp_src, len);
	else
	{
		len -= 1;
		while (len > 0)
		{
			tmp_dst[len] = tmp_src[len];
			len--;
		}
		tmp_dst[0] = tmp_src[0];
	}
	return (dst);
}
