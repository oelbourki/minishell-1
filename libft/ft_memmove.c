/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:10:23 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 19:10:25 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*d;
	char			*s;

	if (len == 0 || (dst == NULL && src == NULL) || (dst == src))
		return (dst);
	d = (char*)dst;
	s = (char*)src;
	if (src > dst)
	{
		return (ft_memcpy(dst, (void*)src, len));
	}
	else
	{
		len--;
		while (len > 0)
		{
			d[len] = s[len];
			len--;
		}
		d[0] = s[0];
		return (dst);
	}
}
