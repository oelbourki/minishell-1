/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:11:05 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/08 10:24:34 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_process(t_flag *strc, va_list ap, int *ret)
{
	if (no_flag(strc) == 1)
		no_flag_process_char(strc, ap, ret);
	if (flag_minus(strc) == 1)
		minus_flag_process_char(strc, ap, ret);
}

void	no_flag_process_char(t_flag *strc, va_list ap, int *ret)
{
	if (strc->width == 0)
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		*ret += 1;
	}
	else
	{
		put_space(strc->width - 1);
		*ret += (strc->width > 1) ? strc->width : 1;
		ft_putchar_fd(va_arg(ap, int), 1);
	}
}

void	minus_flag_process_char(t_flag *strc, va_list ap, int *ret)
{
	if (strc->width == 0)
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		*ret += 1;
	}
	else
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		put_space(strc->width - 1);
		*ret += (strc->width > 1) ? strc->width : 1;
	}
}
