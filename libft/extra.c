/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:34:46 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:27:16 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		taskoned5(const char *s, int *i, t_print *tmp1)
{
	t_print *tmp;

	tmp = tmp1;
	if (s[*i] == 'h')
	{
		if (s[*i + 1] != 'h')
		{
			tmp->type = s[++(*i)];
			tmp->h = 1;
		}
		else
		{
			tmp->h1 = 1;
			(*i)++;
			tmp->type = s[++(*i)];
		}
	}
	else
		tmp->type = s[(*i)];
}

void		taskoned4(const char *s, int *i, t_print *tmp1)
{
	t_print *tmp;

	tmp = tmp1;
	if (s[*i] == 'l')
	{
		if (s[*i + 1] != 'l')
		{
			tmp->type = s[++(*i)];
			tmp->l = 1;
		}
		else
		{
			tmp->lon = 1;
			(*i)++;
			tmp->type = s[++(*i)];
		}
	}
	else
		taskoned5(s, i, tmp1);
}

size_t		wcslen1(wchar_t *wcs)
{
	size_t i;

	i = 0;
	while (wcs[i])
		i++;
	return (i * 4);
}
