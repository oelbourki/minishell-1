/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:27:20 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 22:27:22 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*finish(unsigned int u, unsigned int j, char *tab)
{
	unsigned int	h;

	h = u;
	while (u > 0)
	{
		u = u / 10;
		j++;
	}
	tab[j] = '\0';
	j--;
	while (h > 0)
	{
		tab[j] = h % 10 + '0';
		h = h / 10;
		j--;
	}
	return (tab);
}

static unsigned int	count(int n)
{
	int				j;
	unsigned int	u;

	j = 0;
	if (n < 0)
	{
		u = (-1) * n;
		j++;
	}
	else
	{
		u = n;
	}
	while (u > 0)
	{
		u = u / 10;
		j++;
	}
	if (n == 0)
		return (1);
	return (j);
}

char				*ft_itoa(int n)
{
	unsigned int	u;
	unsigned int	j;
	char			*tab;

	tab = (char*)malloc((count(n) + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	u = n;
	j = 0;
	if (n < 0)
	{
		u = (-1) * n;
		tab[0] = '-';
		j = 1;
	}
	else if (n == 0)
	{
		tab[0] = '0';
		tab[1] = '\0';
		return (tab);
	}
	return (finish(u, j, tab));
}
