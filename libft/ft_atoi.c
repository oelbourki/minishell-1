/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:42:07 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 18:42:19 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	int a;
	int b;

	a = c == ' ' || c == '\t' || c == '\n';
	b = c == '\v' || c == '\f' || c == '\r';
	if (a || b)
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *s)
{
	int					i;
	unsigned long int	r;
	int					sign;

	i = 0;
	r = 0;
	sign = 1;
	while (ft_isspace(s[i]) && s[i] != '\0')
		i++;
	if ((s[i] == '+' || s[i] == '-'))
	{
		sign = (s[i] == '+') - (s[i] == '-');
		i++;
	}
	while ((s[i] <= '9' && s[i] >= '0'))
	{
		r = (r * 10 + s[i] - 48);
		if (r > 9223372036854775807 && sign == -1)
			return (0);
		else if (r > 9223372036854775807)
			return (-1);
		i++;
	}
	return (sign * r);
}
