/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:45:05 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:27:16 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		handel_withoutprec(t_print *ele)
{
	int i;
	int l;

	i = 0;
	l = ft_strlen(ele->arg);
	if (ele->min > l)
	{
		if (ele->left)
			return (write(1, ele->arg, l) + printspaces(ele->min - l));
		else
			return (printspaces(ele->min - l) + write(1, ele->arg, l));
	}
	else
		return (write(1, ele->arg, l));
}

static int		handel_withprec1(t_print *ele, int l, int i)
{
	i = 0;
	if (ele->min <= l && ele->prec_val > l)
		i += write(1, ele->arg, l);
	if (ele->min <= l && ele->prec_val <= l)
	{
		if (ele->left)
		{
			write(1, ele->arg, ele->prec_val);
			printspaces(ele->min - ele->prec_val);
			if (ele->min - ele->prec_val <= 0)
				i += ele->prec_val;
			else
				i += ele->min;
		}
		else
		{
			printspaces(ele->min - ele->prec_val);
			write(1, ele->arg, ele->prec_val);
			if (ele->min - ele->prec_val <= 0)
				i += ele->prec_val;
			else
				i += ele->min;
		}
	}
	return (i);
}

static int		handel_withprec(t_print *ele)
{
	int i;
	int l;
	int h;

	i = 0;
	l = ft_strlen(ele->arg);
	h = ele->min - ele->prec_val;
	if (ele->prec == 0 && ele->min == 0)
		return (0);
	if (ele->min > l && ele->prec_val < l)
	{
		if (ele->left)
			i += write(1, ele->arg, ele->prec_val) + printspaces(h);
		else
			i += printspaces(h) + write(1, ele->arg, ele->prec_val);
	}
	if (ele->min > l && ele->prec_val >= l)
	{
		if (ele->left)
			i += write(1, ele->arg, l) + printspaces(ele->min - l);
		else
			i += printspaces(ele->min - l) + write(1, ele->arg, l);
	}
	i += handel_withprec1(ele, l, i);
	return (i);
}

int				handel(t_print *ele)
{
	int i;

	if (ele->arg == NULL)
		ele->arg = "(null)";
	if (ele->min < 0)
	{
		ele->min = abs(ele->min);
		ele->left = 1;
	}
	if (ele->prec_val < 0)
	{
		ele->prec = 1;
		ele->prec_val = ft_strlen(ele->arg);
	}
	if (ele->precs)
		i = handel_withprec(ele);
	else
		i = handel_withoutprec(ele);
	return (i);
}
