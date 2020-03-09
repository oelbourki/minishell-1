/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:55:16 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:45:59 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		detect(char c)
{
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (0);
	return (1);
}

int		detect_base(char c)
{
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	else
		return (10);
}

int		printspaces(int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		printzeros(int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int		ft_free_p(void *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (0);
}
