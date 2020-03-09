/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:33:53 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:27:16 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		whatl1(t_print *ele, va_list ap)
{
	t_print		*tmp;

	tmp = ele;
	if (tmp->type == 'd' || tmp->type == 'i')
	{
		tmp->i = va_arg(ap, long int);
		return (handen(ele));
	}
	else if (tmp->type == 'u')
	{
		tmp->u = va_arg(ap, unsigned long int);
		return (handeu(ele));
	}
	return (0);
}

int		whatl(t_print *ele, va_list ap)
{
	t_print		*tmp;
	char		c;

	tmp = ele;
	c = tmp->type;
	if (c == 's' || c == 'S')
	{
		tmp->arg1 = va_arg(ap, wchar_t *);
		return (handels(ele));
	}
	if (c == 'c')
	{
		tmp->c1 = va_arg(ap, wchar_t);
		return (handelcl(ele));
	}
	if (c == 'x' || c == 'X')
	{
		tmp->u = va_arg(ap, unsigned long int);
		return (handexl(ele));
	}
	else
		return (whatl1(ele, ap));
}
