/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:09:16 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 19:09:19 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;
	int		i;
	size_t	l;

	if ((dst == NULL && src == NULL) || (dst == src))
		return (NULL);
	l = 0;
	i = 0;
	s = (char*)src;
	d = (char*)dst;
	while (l < n)
	{
		d[i] = s[i];
		i++;
		l++;
	}
	return (d);
}
