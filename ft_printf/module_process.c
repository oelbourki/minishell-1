/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:34:32 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/08 11:49:27 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	module_process(t_flag *strc, int *ret)
{
	if (no_flag(strc) == 1)
		no_flag_process_module(strc, ret, 0);
	if (flag_minus(strc) == 1)
		no_flag_process_module(strc, ret, 1);
	if (flag_zero(strc) == 1)
		zero_flag_process_module(strc, ret);
}

void	no_flag_process_module(t_flag *strc, int *ret, int minus)
{
	int		nb_space;

	if (minus == 1)
		ft_putchar_fd('%', 1);
	nb_space = strc->width - 1;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	*ret += nb_space + 1;
	put_space(nb_space);
	if (minus == 0)
		ft_putchar_fd('%', 1);
}

void	zero_flag_process_module(t_flag *strc, int *ret)
{
	int		nb_zero;

	nb_zero = strc->width - 1;
	nb_zero = (nb_zero < 0) ? 0 : nb_zero;
	*ret += nb_zero + 1;
	put_zero(nb_zero);
	ft_putchar_fd('%', 1);
}
