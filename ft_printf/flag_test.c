/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:19:49 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/08 14:40:09 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		no_flag(t_flag *strc)
{
	if (strc->minus == 0 && strc->zero == 0)
		return (1);
	return (0);
}

int		flag_zero(t_flag *strc)
{
	if (strc->zero == 1)
		return (1);
	return (0);
}

int		flag_minus(t_flag *strc)
{
	if (strc->minus == 1)
		return (1);
	return (0);
}
