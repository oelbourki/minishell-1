/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:44:54 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:27:16 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		what2(t_print *ele, va_list ap, int n)
{
	if ((ele)->l)
	{
		(ele)->r1 = va_arg(ap, long int*);
		*((ele)->r1) = n;
	}
	else if ((ele)->lon)
	{
		(ele)->r2 = va_arg(ap, long long int*);
		*((ele)->r2) = n;
	}
	else if ((ele)->h)
	{
		(ele)->s = va_arg(ap, signed char*);
		*((ele)->s) = n;
	}
	else if ((ele)->h1)
	{
		(ele)->s1 = va_arg(ap, short int*);
		*((ele)->s1) = n;
	}
	else
	{
		(ele)->r = va_arg(ap, int*);
		*((ele)->r) = n;
	}
}

int			what1(t_print *ele, va_list ap)
{
	t_print		*tmp;

	tmp = ele;
	if (tmp->type == 'p')
	{
		tmp->u = va_arg(ap, unsigned long);
		return (handep(tmp,
		itoa_base10(tmp->u, 16, 1)));
	}
	else if (tmp->type == 'd' || tmp->type == 'i')
	{
		tmp->i = va_arg(ap, int);
		return (handen(ele));
	}
	else if (tmp->type == 'u')
	{
		tmp->u = va_arg(ap, unsigned int);
		return (handeu(ele));
	}
	if (tmp->type == 'c')
	{
		tmp->c = va_arg(ap, int);
		return (handelc(ele));
	}
	return (0);
}

int			what(t_print *ele, va_list ap, int n)
{
	if ((ele)->type == '%')
		return (handelper(ele));
	if ((ele)->l)
		return (whatl(ele, ap));
	if ((ele)->lon)
		return (whatll(ele, ap));
	if ((ele)->h || (ele)->h1)
		return (whath(ele, ap));
	if ((ele)->type == 's' || (ele)->type == 'S')
	{
		(ele)->arg = va_arg(ap, char *);
		return (handel(ele));
	}
	if ((ele)->type == 'x' || (ele)->type == 'X')
	{
		ele->u = va_arg(ap, unsigned int);
		(ele)->arg = itoa_base10(ele->u, 16,
		((ele)->type == 'x'));
		return (handex(ele));
	}
	else if ((ele)->type == 'n')
		what2(ele, ap, n);
	else
		return (what1(ele, ap));
	return (0);
}
