/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:05:44 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:27:16 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		whatll(t_print *ele, va_list ap)
{
	t_print		*tmp;

	tmp = ele;
	if (tmp->type == 'x' || tmp->type == 'X')
	{
		tmp->lu = va_arg(ap, unsigned long long int);
		return (handexll(ele));
	}
	else if (tmp->type == 'd' || tmp->type == 'i')
	{
		tmp->i = va_arg(ap, long long int);
		return (handen(ele));
	}
	else if (tmp->type == 'u')
	{
		tmp->lu = va_arg(ap, unsigned long long int);
		return (handeull(ele));
	}
	return (0);
}
