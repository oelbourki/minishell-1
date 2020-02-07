/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:10:19 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/07 16:11:01 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_limit_fd(char *s, int fd, int limit)
{
	int		index;
	char	*p;
	int		i;

	index = 0;
	i = 0;
	if (s == NULL)
	{
		p = ft_strdup("(null)");
		while (p[i] != '\0' && index++ < limit)
		{
			ft_putchar_fd(p[i], fd);
			i++;
		}
		free(p);
	}
	else
	{
		while (*s != '\0' && index++ < limit)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

void	putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
