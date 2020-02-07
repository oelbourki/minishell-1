/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:15:56 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/10 00:14:13 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	integer_process(t_flag *strc, va_list ap, int *ret)
{
	va_list	ap2;

	va_copy(ap2, ap);
	if (strc->dot == 1 && va_arg(ap2, int) == 0 && strc->precesion == 0)
	{
		put_space(strc->width);
		*ret += strc->width;
		va_arg(ap, int);
		va_end(ap2);
		return ;
	}
	if (no_flag(strc) == 1)
		no_flag_process_int(strc, ap, ret);
	if (flag_zero(strc) == 1)
		zero_flag_process_int(strc, ap, ret);
	if (flag_minus(strc) == 1)
		minus_flag_process_int(strc, ap, ret);
	va_end(ap2);
}

void	no_flag_process_int(t_flag *strc, va_list ap, int *ret)
{
	long	number;
	int		nb_space;
	int		nb_zero;

	number = va_arg(ap, int);
	if (strc->precesion < cnt_digit(number))
		strc->precesion = 0;
	nb_space = strc->width - strc->precesion - cnt_digit(number);
	if (strc->width > cnt_digit(number) && strc->precesion >= cnt_digit(number))
		nb_space += cnt_digit(number);
	nb_zero = strc->precesion - cnt_digit(number);
	nb_zero += (number < 0) ? 1 : 0;
	nb_space -= (number < 0 && strc->dot == 1 && strc->precesion != 0) ? 1 : 0;
	nb_zero = (nb_zero < 0) ? 0 : nb_zero;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	*ret += nb_zero + nb_space + cnt_digit(number);
	put_space(nb_space);
	if (number < 0)
	{
		ft_putchar_fd('-', 1);
		number *= -1;
	}
	if (strc->dot)
		put_zero(nb_zero);
	ft_putnbr_fd(number, 1);
}

void	zero_flag_process_int(t_flag *strc, va_list ap, int *ret)
{
	long	number;
	int		nb_space;
	int		nb_zero;

	number = va_arg(ap, int);
	if (strc->precesion < cnt_digit(number))
		strc->precesion = 0;
	nb_space = strc->width - strc->precesion - cnt_digit(number);
	if (strc->width > cnt_digit(number) && strc->precesion >= cnt_digit(number))
		nb_space += cnt_digit(number);
	nb_zero = strc->precesion - cnt_digit(number);
	nb_zero += (number < 0) ? 1 : 0;
	nb_space += (number < 0 && strc->precesion > cnt_digit(number)) ? -1 : 0;
	nb_zero = (nb_zero < 0) ? 0 : nb_zero;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	*ret += nb_zero + nb_space + cnt_digit(number);
	resume_zero_flag_int(strc, &number, nb_space);
	if (number < 0)
	{
		ft_putchar_fd('-', 1);
		number *= -1;
	}
	if (strc->dot)
		put_zero(nb_zero);
	ft_putnbr_fd(number, 1);
}

void	resume_zero_flag_int(t_flag *strc, long *number, int nb_space)
{
	if (strc->dot == 0)
	{
		if (*number < 0)
		{
			ft_putchar_fd('-', 1);
			*number *= -1;
		}
		put_zero(nb_space);
	}
	else
		put_space(nb_space);
}

void	minus_flag_process_int(t_flag *strc, va_list ap, int *ret)
{
	long	number;
	int		nb_space;
	int		nb_zero;

	number = va_arg(ap, int);
	nb_space = 0;
	if (number < 0)
	{
		*ret += ft_putchar_fd('-', 1);
		number *= -1;
		nb_space -= 1;
	}
	if (strc->precesion < cnt_digit(number))
		strc->precesion = cnt_digit(number);
	nb_space += strc->width - strc->precesion;
	nb_zero = strc->precesion - cnt_digit(number);
	nb_zero += (strc->precesion > strc->width && number < 0) ? 1 : 0;
	nb_zero = (nb_zero < 0) ? 0 : nb_zero;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	nb_zero += (number < 0) ? 1 : 0;
	*ret += nb_zero + nb_space + cnt_digit(number);
	if (strc->dot)
		put_zero(nb_zero);
	ft_putnbr_fd(number, 1);
	put_space(nb_space);
}
