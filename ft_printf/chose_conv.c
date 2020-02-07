/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:56:37 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/08 14:34:58 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chose_convertion(const char *format, int *ret, int i, va_list ap)
{
	t_flag		strc;

	i = fill_flag_strc(format, i, ap, &strc);
	if (strc.conver == 'd' || strc.conver == 'i')
		integer_process(&strc, ap, ret);
	if (strc.conver == 'u')
		unsigned_int_process(&strc, ap, ret);
	if (strc.conver == 'x' || strc.conver == 'X')
		hex_process(&strc, ap, ret);
	if (strc.conver == 'p')
		pointer_process(&strc, ap, ret);
	if (strc.conver == 'c')
		char_process(&strc, ap, ret);
	if (strc.conver == 's')
		string_process(&strc, ap, ret);
	if (strc.conver == '%')
		module_process(&strc, ret);
}
