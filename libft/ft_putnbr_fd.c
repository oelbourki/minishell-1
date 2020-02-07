/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:38:43 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/11 10:38:45 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	u;

	u = n;
	if (n < 0)
	{
		u = (-1) * n;
		ft_putchar_fd('-', fd);
	}
	if (u >= 10)
	{
		ft_putnbr_fd(u / 10, fd);
	}
	c = (u % 10) + '0';
	ft_putchar_fd(c, fd);
}
