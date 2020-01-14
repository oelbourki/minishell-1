/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:57:12 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/16 22:20:53 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		ft_sign(char c, int *i)
{
	if (c == '-')
	{
		*i += 1;
		return (-1);
	}
	if (c == '+')
	{
		*i += 1;
		return (1);
	}
	return (1);
}

int				ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	sign = ft_sign(str[i], &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res >= 922337203685477580 && (str[i] - '0') >= 7)
		{
			if (str[i] - '0' >= 8 && sign == -1)
				return (0);
			return (-1);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * (int)res);
}
