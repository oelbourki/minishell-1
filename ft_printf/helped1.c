/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helped1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:37:18 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/09 20:45:34 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cnt_digit(long number)
{
	int		count;

	count = 0;
	if (number < 0)
	{
		count += 1;
		number *= -1;
	}
	if (number == 0)
		return (1);
	while (number != 0)
	{
		count++;
		number /= 10;
	}
	return (count);
}

void	put_space(int nb_space)
{
	while (nb_space-- > 0)
		ft_putchar_fd(' ', 1);
}

void	put_zero(int nb_zero)
{
	while (nb_zero-- > 0)
		ft_putchar_fd('0', 1);
}

int		unsigned_cnt_digit(unsigned int number)
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

char	*itoa_base(unsigned int number, int base)
{
	char	*str;
	int		mod;
	int		i;

	str = (char*)malloc(cnt_digit(number) + 1);
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
