/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:36:05 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/16 22:21:22 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_min(int n, char *str, int *i)
{
	if (n == -2147483648)
	{
		str[*i] = '-';
		*i += 1;
		str[*i] = '2';
		*i += 1;
		return (147483648);
	}
	return (n);
}

static int		nb_size(int n, int *nb_ten)
{
	int		size;

	size = 1;
	if (n == -2147483648)
	{
		size += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		n = (-1) * n;
		size += 1;
	}
	while ((n / *nb_ten) > 9)
	{
		*nb_ten *= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		nb_ten;
	int		size;

	i = 0;
	nb_ten = 1;
	size = nb_size(n, &nb_ten);
	str = (char*)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	n = is_min(n, str, &i);
	if (n < 0)
	{
		str[i++] = '-';
		n = (-1) * n;
	}
	while (nb_ten != 0)
	{
		str[i++] = (n / nb_ten) + '0';
		n -= (n / nb_ten) * nb_ten;
		nb_ten /= 10;
	}
	str[i] = '\0';
	return (str);
}
