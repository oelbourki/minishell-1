/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:44:00 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/08 14:42:24 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_process(t_flag *strc, va_list ap, int *ret)
{
	if (no_flag(strc) == 1)
	{
		if (strc->dot == 0)
			flag_process_string_nodot(strc, ap, ret, 0);
		else
			flag_process_string_dot(strc, ap, ret, 0);
	}
	if (flag_minus(strc) == 1)
	{
		if (strc->dot == 0)
			flag_process_string_nodot(strc, ap, ret, 1);
		else
			flag_process_string_dot(strc, ap, ret, 1);
	}
}

void	flag_process_string_nodot(t_flag *strc, va_list ap, int *ret, int minus)
{
	int		nb_space;
	char	*chain;
	int		len;

	chain = va_arg(ap, char*);
	if (chain == NULL)
		len = 6;
	else
		len = ft_strlen(chain);
	nb_space = strc->width - len;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	*ret += nb_space + len;
	if (minus == 1)
		ft_putstr_fd(chain, 1);
	put_space(nb_space);
	if (minus == 0)
		ft_putstr_fd(chain, 1);
}

void	flag_process_string_dot(t_flag *strc, va_list ap, int *ret, int minus)
{
	int		nb_space;
	char	*chain;
	int		len;

	chain = va_arg(ap, char*);
	if (chain == NULL)
		len = (strc->precesion > 6) ? 6 : strc->precesion;
	else
		len = (strc->precesion > ft_strlen(chain)) ? ft_strlen(chain)
		: strc->precesion;
	nb_space = strc->width - len;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	*ret += nb_space + len;
	if (minus == 1)
		ft_putstr_limit_fd(chain, 1, len);
	put_space(nb_space);
	if (minus == 0)
		ft_putstr_limit_fd(chain, 1, len);
}
