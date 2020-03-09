/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:44:43 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:27:16 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		taskoned(const char *s, va_list ap, t_print *tmp, int flag1)
{
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	while (s[i] != '\0' && s[i] != '.' && !isin(s[i]) && flag1 == 1)
	{
		if (s[i] == '-' && tmp->left == 0)
			tmp->left = 1;
		if (s[i] == '0' && s[i + 1] != '\0' &&
		((s[i + 1] == '-' || s[i - 1] == '-') ||
		(ft_isdigit(s[i + 1]) && s[i + 1] != '0') || s[i + 1] == '*'))
			tmp->zero = 1;
		if (s[i] == '*' && tmp->min == 0)
			tmp->min = va_arg(ap, int);
		if (ft_isdigit(s[i]) && flag == 1)
		{
			tmp->min = ft_atoi(s + i);
			flag = 0;
		}
		if (s[i + 1] == '%')
			flag1 = 0;
		i++;
	}
	return (i);
}

int		taskoned2(const char *s, int *f, int *c)
{
	int		i;

	i = 0;
	if (s[i + 1] == '%')
	{
		write(1, "%", 1);
		*f += 1;
		return (1);
	}
	i++;
	while (isin2(s[i]) && s[i] != '\0')
		i++;
	if (s[i] == '%' && i != 0)
		*c = i;
	return (0);
}

int		taskoned3(const char *s, va_list ap, int i, t_print *tmp)
{
	int flag;

	flag = 1;
	tmp->precs = 1;
	while (s[i] != '\0' && !isin(s[i]))
	{
		if (s[i] == '*')
		{
			tmp->prec_val = va_arg(ap, int);
			tmp->prec = 1;
		}
		if (ft_isdigit(s[i]) && flag == 1)
		{
			tmp->prec_val = ft_atoi(s + i);
			tmp->zero = 0;
			flag = 0;
			tmp->prec = 1;
		}
		i++;
	}
	return (i);
}

int		taskone(const char *s, va_list ap, int *f, int n)
{
	t_print		tmp;
	int			i;
	int			c;

	init(&tmp);
	i = 0;
	c = 0;
	if (taskoned2(s, f, &c))
		return (1);
	i = taskoned(s, ap, &tmp, 1);
	if (s[i] == '.' && c == 0)
		i = taskoned3(s, ap, i, &tmp);
	if (c)
	{
		tmp.type = '%';
		*f += c;
		return (what(&tmp, ap, n));
	}
	taskoned4(s, &i, &tmp);
	*f += i;
	return (what(&tmp, ap, n));
}

int		ft_printf(const char *s, ...)
{
	int		x;
	int		i;
	int		j;
	int		l;
	va_list	ap;

	x = 0;
	i = -1;
	j = 0;
	l = ft_strlen(s);
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%' && i < l)
			x += taskone(s + i, ap, &i, x + j);
		else
		{
			if (i < l)
				j += write(1, &s[i], 1);
			else
				break ;
		}
	}
	va_end(ap);
	return (x + j);
}
