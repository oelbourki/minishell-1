/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:43:31 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/08 10:25:37 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	ap;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[++i] != '%')
		{
			chose_convertion(format, &ret, i, ap);
			while (!ft_strchr("xXpcsdiu%", format[i++]))
				;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
			ret += 1;
		}
	}
	va_end(ap);
	return (ret);
}
