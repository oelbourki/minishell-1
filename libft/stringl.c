/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:32:32 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:27:16 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		handel_withoutprec(t_print *ele)
{
	int i;
	int l;

	i = 0;
	l = wcslen1(ele->arg1);
	if (ele->min > l)
	{
		if (ele->left)
			return (write(1, ele->arg1, l) + printspaces(ele->min - l));
		else
			return (printspaces(ele->min - l) + write(1, ele->arg1, l));
	}
	else
		return (write(1, ele->arg1, l));
}

static int		handel_withprec1(t_print *ele, int l, int i)
{
	i = 0;
	if (ele->min <= l && ele->prec_val > l)
		i += write(1, ele->arg1, l);
	if (ele->min <= l && ele->prec_val <= l)
	{
		if (ele->left)
		{
			write(1, ele->arg1, ele->prec_val);
			printspaces(ele->min - ele->prec_val);
			if (ele->min - ele->prec_val <= 0)
				i += ele->prec_val;
			else
				i += ele->min;
		}
		else
		{
			printspaces(ele->min - ele->prec_val);
			write(1, ele->arg1, ele->prec_val);
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
	l = wcslen1(ele->arg1);
	h = ele->min - ele->prec_val;
	if (ele->prec == 0 && ele->min == 0)
		return (0);
	if (ele->min > l && ele->prec_val < l)
	{
		if (ele->left)
			i += write(1, ele->arg1, ele->prec_val) + printspaces(h);
		else
			i += printspaces(h) + write(1, ele->arg1, ele->prec_val);
	}
	if (ele->min > l && ele->prec_val >= l)
	{
		if (ele->left)
			i += write(1, ele->arg1, l) + printspaces(ele->min - l);
		else
			i += printspaces(ele->min - l) + write(1, ele->arg1, l);
	}
	i += handel_withprec1(ele, l, i);
	return (i);
}

int				handels(t_print *ele)
{
	if (ele->arg1 == NULL)
		ele->arg1 = L"(null)";
	if (ele->min < 0)
	{
		ele->min = abs(ele->min);
		ele->left = 1;
	}
	if (ele->prec_val < 0)
	{
		ele->prec = 1;
		ele->prec_val = wcslen1(ele->arg1);
	}
	if (ele->precs)
		return (handel_withprec(ele));
	else
		return (handel_withoutprec(ele));
}
