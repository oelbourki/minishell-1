/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helped2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:23:48 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/09 21:06:08 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

char			*string_toupper(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

static int		unsigned_long_cnt_digit(unsigned long number)
{
	int		count;

	count = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		count++;
		number /= 10;
	}
	return (count);
}

char			*unsigned_l_itoa_base(size_t number, int base)
{
	char	*str;
	int		mod;
	int		i;

	str = (char*)malloc(unsigned_long_cnt_digit(number) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	if (number == 0)
		str[i++] = '0';
	while (number != 0)
	{
		mod = number % base;
		if (mod < 10)
			str[i++] = mod + 48;
		else
			str[i++] = mod + 87;
		number /= base;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
