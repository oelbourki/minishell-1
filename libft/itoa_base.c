/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:49:50 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:27:16 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fix(char *buffer, int i)
{
	int x;

	x = i;
	while (x < 20)
	{
		buffer[x] = '\0';
		x++;
	}
}

char			*extra(long long int u, int base, int l, char *buffer)
{
	long long int	h;
	int				i;
	int				one;

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

char			*itoa_base(long long int h, int base, int g)
{
	long long int	u;
	int				l;
	char			*buffer;

	buffer = (char*)malloc(20);
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
	if (h < 0)
		u = -h;
	else
		u = h;
	return (extra(u, base, l, buffer));
}
