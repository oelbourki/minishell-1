/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:45:33 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:45:59 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		handel_withoutprec(t_print *ele)
{
	int		i;
	char	*s;
	int		l;

	i = 0;
	s = itoa_base(ele->u, detect_base(ele->type), 0);
	l = ft_strlen(s);
	if (ele->left)
	{
		i += write(1, s, l);
		if (ele->min > l)
			i += printspaces(ele->min - l);
	}
	else
	{
		if (ele->min > l && ele->zero == 0)
			i += printspaces(ele->min - l);
		if (ele->min > l && ele->zero == 1)
			i += printzeros(ele->min - l);
		i += write(1, s, l);
	}
	ft_free_p(s);
	return (i);
}

static int		handel_withprec_zeros(t_print *ele)
{
	int		i;
	char	*s;
	int		l;

	i = 0;
	s = itoa_base(ele->u, detect_base(ele->type), 0);
	l = ft_strlen(s);
	if (ele->min > l && ele->zero == 1)
		i += printzeros(ele->min - l);
	i += write(1, s, l);
	ft_free_p(s);
	return (i);
}

static int		handel_withprec2(t_print *ele, char *s, int l)
{
	int i;

	i = 0;
	if (ele->prec_val > l)
	{
		if (ele->left)
		{
			i += printzeros(ele->prec_val - l) + write(1, s, l);
			i += printspaces(ele->min - ele->prec_val);
		}
		else
		{
			i += printspaces(ele->min - ele->prec_val);
			i += printzeros(ele->prec_val - l) + write(1, s, l);
		}
	}
	else
	{
		if (ele->left)
			i += write(1, s, l) + printspaces(ele->min - l);
		else
			i += printspaces(ele->min - l) + write(1, s, l);
	}
	return (i);
}

static int		handel_withprec(t_print *ele)
{
	int		i;
	char	*s;
	int		l;

	i = 0;
	s = itoa_base(ele->u, detect_base(ele->type), 0);
	l = ft_strlen(s);
	if (l >= MAX(ele->prec_val, ele->min))
		return (write(1, s, l) + ft_free_p(s));
	if (ele->prec_val < ele->min)
		i = handel_withprec2(ele, s, l);
	else if (ele->prec_val >= ele->min)
		i += printzeros(ele->prec_val - l) + write(1, s, l);
	return (i + ft_free_p(s));
}

int				handeu(t_print *ele)
{
	int i;

	if (ele->min < 0)
	{
		ele->min = abs(ele->min);
		ele->left = 1;
	}
	if (ele->prec_val < 0)
	{
		ele->prec = 0;
		ele->prec_val = 0;
	}
	if (ele->u == 0 && ele->prec_val == 0 && ele->precs)
	{
		printspaces(ele->min);
		return ((ele->min));
	}
	if (ele->zero == 1 && ele->prec_val == 0)
		i = (handel_withprec_zeros(ele));
	else if (ele->prec)
		i = (handel_withprec(ele));
	else
		i = (handel_withoutprec(ele));
	return (i);
}
