/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:44:32 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:27:16 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			isin(char c)
{
	char	*set;
	int		i;

	set = "cspdiuxXnl";
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			isin2(char c)
{
	char	*set;
	int		i;

	set = "0-.*123456789";
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	init1(t_print *tmp)
{
	tmp->r1 = 0;
	tmp->r2 = 0;
	tmp->l = 0;
	tmp->lon = 0;
	tmp->u = 0;
	tmp->lu = 0;
	tmp->s = 0;
	tmp->s1 = 0;
	tmp->base = 0;
	tmp->precs = 0;
}

void		init(t_print *tmp)
{
	tmp->h = 0;
	tmp->h1 = 0;
	tmp->left = 0;
	tmp->zero = 0;
	tmp->min = 0;
	tmp->prec = 0;
	tmp->prec_val = 0;
	tmp->type = 0;
	tmp->arg = 0;
	tmp->arg1 = 0;
	tmp->c = 0;
	tmp->c1 = 0;
	tmp->i = 0;
	tmp->r = 0;
	init1(tmp);
}
