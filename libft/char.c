/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:55:28 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:27:16 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		handelc(t_print *ele)
{
	int i;

	i = 0;
	if (ele->min > 1)
	{
		if (ele->left)
		{
			i = write(1, &ele->c, 1) + printspaces(ele->min - 1);
		}
		else
			i = printspaces(ele->min - 1) + write(1, &ele->c, 1);
	}
	else
		i = write(1, &ele->c, 1);
	return (i);
}
