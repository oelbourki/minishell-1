/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:08:58 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/10 00:14:14 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_process(t_flag *strc, va_list ap, int *ret)
{
	va_list	ap2;

	va_copy(ap2, ap);
	if (strc->dot == 1 && va_arg(ap2, unsigned int) == 0
	&& strc->precesion == 0)
	{
		put_space(strc->width);
		*ret += strc->width;
		va_arg(ap, unsigned int);
		va_end(ap2);
		return ;
	}
	if (no_flag(strc) == 1)
		hex_no_flag(strc, ap, ret);
	if (flag_zero(strc) == 1)
		hex_zero_flag(strc, ap, ret);
	if (flag_minus(strc) == 1)
		hex_minus_flag(strc, ap, ret);
	va_end(ap2);
}

void	hex_no_flag(t_flag *strc, va_list ap, int *ret)
{
	char	*hex;
	int		nb_space;
	int		nb_zero;

	hex = itoa_base(va_arg(ap, unsigned int), 16);
	if (strc->conver == 'X')
		hex = string_toupper(hex);
	if (strc->precesion < ft_strlen(hex))
		strc->precesion = 0;
	nb_space = strc->width - strc->precesion - ft_strlen(hex);
	if (strc->width > ft_strlen(hex) && strc->precesion >= ft_strlen(hex))
		nb_space += ft_strlen(hex);
	nb_zero = strc->precesion - ft_strlen(hex);
	nb_zero = (nb_zero < 0) ? 0 : nb_zero;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	*ret += nb_zero + nb_space + ft_strlen(hex);
	put_space(nb_space);
	put_zero(nb_zero);
	ft_putstr_fd(hex, 1);
	free(hex);
}

void	hex_zero_flag(t_flag *strc, va_list ap, int *ret)
{
	char	*hex;
	int		nb_space;
	int		nb_zero;

	hex = itoa_base(va_arg(ap, unsigned int), 16);
	if (strc->conver == 'X')
		hex = string_toupper(hex);
	if (strc->precesion < ft_strlen(hex))
		strc->precesion = 0;
	nb_space = strc->width - strc->precesion - ft_strlen(hex);
	if (strc->width > ft_strlen(hex) && strc->precesion >= ft_strlen(hex))
		nb_space += ft_strlen(hex);
	nb_zero = strc->precesion - ft_strlen(hex);
	nb_zero = (nb_zero < 0) ? 0 : nb_zero;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	*ret += nb_zero + nb_space + ft_strlen(hex);
	if (strc->dot == 1)
		put_space(nb_space);
	else
		put_zero(nb_space);
	put_zero(nb_zero);
	ft_putstr_fd(hex, 1);
	free(hex);
}

void	hex_minus_flag(t_flag *strc, va_list ap, int *ret)
{
	char	*hex;
	int		nb_space;
	int		nb_zero;

	hex = itoa_base(va_arg(ap, unsigned int), 16);
	if (strc->conver == 'X')
		hex = string_toupper(hex);
	if (strc->precesion < ft_strlen(hex))
		strc->precesion = ft_strlen(hex);
	nb_space = strc->width - strc->precesion;
	nb_zero = strc->precesion - ft_strlen(hex);
	nb_zero = (nb_zero < 0) ? 0 : nb_zero;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	*ret += nb_zero + nb_space + ft_strlen(hex);
	put_zero(nb_zero);
	ft_putstr_fd(hex, 1);
	put_space(nb_space);
	free(hex);
}
