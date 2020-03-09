/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:49:57 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:27:16 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fix(char *buffer, int i)
{
	int x;

	x = i;
	while (x < 25)
	{
		buffer[x] = '\0';
		x++;
	}
}

static char		*extra(unsigned long long u, int base, int l, char *buffer)
{
	unsigned long long		h;
	int						i;
	unsigned long long		one;

	i = 0;
	h = u;
	while (u != 0)
	{
		u = u / base;
		i++;
	}
	fix(buffer, i);
	i--;
	while (h != 0)
	{
		one = h % base;
		if (one < 10)
			buffer[i] = one + 48;
		else
			buffer[i] = one + l;
		i--;
		h = h / base;
	}
	buffer[i] = '\0';
	return (buffer);
}

char			*itoa_base10(unsigned long long h, int base, int g)
{
	int					l;
	char				*buffer;

	buffer = (char*)malloc(25);
	if (g == 0)
		l = 55;
	else if (g == 1)
		l = 87;
	if (h == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (buffer);
	}
	return (extra(h, base, l, buffer));
}
