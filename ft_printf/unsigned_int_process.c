/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:21:43 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/07 16:04:33 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_int_process(t_flag *strc, va_list ap, int *ret)
{
	va_list	ap2;

	va_copy(ap2, ap);
	if (strc->dot == 1 && va_arg(ap2, unsigned int) == 0 &&
	strc->precesion == 0)
	{
		put_space(strc->width);
		*ret += strc->width;
		va_arg(ap, unsigned int);
		return ;
	}
	if (no_flag(strc) == 1)
		unsigned_int_no_flag(strc, ap, ret);
	if (flag_zero(strc) == 1)
		unsigned_int_zero_flag(strc, ap, ret);
	if (flag_minus(strc) == 1)
		unsigned_int_minus_flag(strc, ap, ret);
	va_end(ap2);
}

void	unsigned_int_no_flag(t_flag *strc, va_list ap, int *ret)
{
	unsigned	int	number;
	int				nb_space;
	int				nb_zero;

	number = va_arg(ap, unsigned int);
	if (strc->precesion < unsigned_cnt_digit(number))
		strc->precesion = 0;
	nb_space = strc->width - strc->precesion - unsigned_cnt_digit(number);
	if (strc->width > unsigned_cnt_digit(number) &&
	strc->precesion >= unsigned_cnt_digit(number))
		nb_space += unsigned_cnt_digit(number);
	nb_zero = strc->precesion - unsigned_cnt_digit(number);
	nb_zero = (nb_zero < 0) ? 0 : nb_zero;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	*ret += nb_zero + nb_space + unsigned_cnt_digit(number);
	put_space(nb_space);
	put_zero(nb_zero);
	putnbr_unsigned_fd(number, 1);
}

void	unsigned_int_zero_flag(t_flag *strc, va_list ap, int *ret)
{
	long	number;
	int		nb_space;
	int		nb_zero;

	number = va_arg(ap, unsigned int);
	if (strc->precesion < unsigned_cnt_digit(number))
		strc->precesion = 0;
	nb_space = strc->width - strc->precesion - unsigned_cnt_digit(number);
	if (strc->width > unsigned_cnt_digit(number) &&
	strc->precesion >= unsigned_cnt_digit(number))
		nb_space += unsigned_cnt_digit(number);
	nb_zero = strc->precesion - unsigned_cnt_digit(number);
	nb_zero = (nb_zero < 0) ? 0 : nb_zero;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	*ret += nb_zero + nb_space + unsigned_cnt_digit(number);
	resume_zero_flag_int(strc, &number, nb_space);
	put_zero(nb_zero);
	putnbr_unsigned_fd(number, 1);
}

void	unsigned_int_minus_flag(t_flag *strc, va_list ap, int *ret)
{
	int		number;
	int		nb_space;
	int		nb_zero;

	number = va_arg(ap, unsigned int);
	if (strc->precesion < unsigned_cnt_digit(number))
		strc->precesion = unsigned_cnt_digit(number);
	nb_space = strc->width - strc->precesion;
	nb_zero = strc->precesion - unsigned_cnt_digit(number);
	nb_zero = (nb_zero < 0) ? 0 : nb_zero;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	*ret += nb_zero + nb_space + unsigned_cnt_digit(number);
	put_zero(nb_zero);
	putnbr_unsigned_fd(number, 1);
	put_space(nb_space);
}
