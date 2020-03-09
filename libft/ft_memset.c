/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:11:03 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 19:11:04 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*f;

	i = 0;
	f = (unsigned char*)b;
	while (i < len)
	{
		*f = (unsigned char)c;
		i++;
		f++;
	}
	return (b);
}
