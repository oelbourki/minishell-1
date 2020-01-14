/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:12:20 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/13 02:25:17 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	ch;
	char	*tmp;

	i = 0;
	ch = (char)c;
	tmp = (char*)str;
	while (tmp[i] != '\0' && tmp[i] != ch)
		i++;
	if (tmp[i] == '\0')
	{
		if (ch == '\0')
			return (tmp + i);
		return (NULL);
	}
	tmp = tmp + i;
	return (tmp);
}
