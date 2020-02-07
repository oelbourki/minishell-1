/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:41:55 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/10 00:23:53 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointer_process(t_flag *strc, va_list ap, int *ret)
{
	va_list	ap2;

	va_copy(ap2, ap);
	if (strc->dot == 1 && va_arg(ap2, size_t) == 0 && strc->precesion == 0)
	{
		if (flag_minus(strc) == 1)
		{
			strc->width++;
			poinet_minus_flag(strc, ap, ret, 1);
		}
		else
		{
			put_space(strc->width - 2);
			ft_putstr_fd("0x", 1);
			*ret += (strc->width) ? strc->width : strc->width + 2;
		}
		va_arg(ap, size_t);
		va_end(ap2);
		return ;
	}
	if (no_flag(strc) == 1)
		poinet_no_flag(strc, ap, ret);
	if (flag_minus(strc) == 1)
		poinet_minus_flag(strc, ap, ret, 0);
	va_end(ap2);
}

void	poinet_no_flag(t_flag *strc, va_list ap, int *ret)
{
	char	*hex;
	int		nb_space;
	int		nb_zero;

	hex = unsigned_l_itoa_base(va_arg(ap, size_t), 16);
	if (strc->conver == 'X')
		hex = string_toupper(hex);
	if (strc->precesion < ft_strlen(hex) + 2)
		strc->precesion = 0;
	nb_space = strc->width - strc->precesion - ft_strlen(hex) - 2;
	if (strc->width > ft_strlen(hex) + 2 &&
	strc->precesion >= ft_strlen(hex) + 2)
		nb_space += ft_strlen(hex) + 2;
	nb_zero = strc->precesion - ft_strlen(hex) + 1;
	nb_zero = (nb_zero < 0) ? 0 : nb_zero;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	*ret += nb_zero + nb_space + ft_strlen(hex) + 2;
	put_space(nb_space);
	put_zero(nb_zero);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(hex, 1);
	free(hex);
}

void	poinet_minus_flag(t_flag *strc, va_list ap, int *ret, int nul)
{
	char	*hex;
	int		nb_space;
	int		size;

	hex = unsigned_l_itoa_base(va_arg(ap, size_t), 16);
	if (strc->conver == 'X')
		hex = string_toupper(hex);
	if (strc->precesion < ft_strlen(hex) + 2)
		strc->precesion = ft_strlen(hex) + 2;
	nb_space = strc->width - strc->precesion;
	nb_space = (nb_space < 0) ? 0 : nb_space;
	size = (ft_strlen(hex) == 1 && *hex == '0' &&
	strc->dot) ? 0 : ft_strlen(hex);
	*ret += nb_space + size + 2;
	ft_putstr_fd("0x", 1);
	if (!nul)
		ft_putstr_fd(hex, 1);
	free(hex);
	put_space(nb_space);
}
