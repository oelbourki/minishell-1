/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flag_strc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:56:44 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/08 18:21:49 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fill_flag_strc(const char *format, int i, va_list ap, t_flag *strc)
{
	init_flag_strc(strc);
	while (format[i] == '0')
	{
		strc->zero = 1;
		i += 1;
	}
	while (format[i] == '-')
	{
		strc->minus = 1;
		(i) += 1;
	}
	strc->star_wid = (format[i] == '*') ? 1 : 0;
	if (ft_isdigit(format[i]) || format[i] == '*')
		strc->width = get_number(format, &i, ap);
	if (format[i] == '.')
	{
		strc->dot = 1;
		i++;
	}
	strc->star_pres = (format[i] == '*') ? 1 : 0;
	if (ft_isdigit(format[i]) || format[i] == '*')
		strc->precesion = get_number(format, &i, ap);
	strc->conver = format[i++];
	optimize_stuct(strc);
	return (i);
}

int		get_number(const char *format, int *i, va_list ap)
{
	int		count;
	char	*str;
	int		remember;

	count = 0;
	remember = *i;
	if (format[*i] == '*')
	{
		(*i) += 1;
		return (va_arg(ap, int));
	}
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		*i += 1;
		count += 1;
	}
	str = (char*)malloc(count + 1);
	*i = remember;
	count = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
		str[count++] = format[(*i)++];
	str[count] = '\0';
	return (ft_atoi(str));
}

void	init_flag_strc(t_flag *strc)
{
	strc->minus = 0;
	strc->zero = 0;
	strc->dot = 0;
	strc->width = 0;
	strc->precesion = 0;
	strc->conver = '~';
	strc->star_wid = 0;
	strc->star_wid = 0;
}

void	optimize_stuct(t_flag *strc)
{
	if (strc->width < 0)
	{
		strc->width *= -1;
		strc->minus = 1;
	}
	if (strc->precesion < 0)
	{
		strc->precesion = 0;
		strc->dot = 0;
	}
}
