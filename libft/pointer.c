/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:53:10 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:45:59 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		handel_withoutprec(int min, int left, char *arg)
{
	int			i;
	int			l;

	l = ft_strlen(arg);
	i = 0;
	if (left)
	{
		i += write(1, "0x", 2);
		i += write(1, arg, l);
		if (min > l + 2)
			i += printspaces(min - l - 2);
	}
	else
	{
		if (min > l + 2)
			i += printspaces(min - l - 2);
		i += write(1, "0x", 2);
		i += write(1, arg, l);
	}
	ft_free_p(arg);
	return (i);
}

int				handep(t_print *tmp, char *arg)
{
	int i;

	i = 0;
	if (tmp->min < 0)
	{
		tmp->min = abs(tmp->min);
		tmp->left = 1;
	}
	if (tmp->u == 0 && tmp->prec_val == 0 && tmp->precs)
	{
		i += printspaces(tmp->min - 2);
		i += write(1, "0x", 2);
		ft_free_p(arg);
		return ((i));
	}
	return (handel_withoutprec(tmp->min, tmp->left, arg));
}
