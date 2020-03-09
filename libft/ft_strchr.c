/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:11:30 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 19:11:32 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		x;
	int			i;
	const char	*d;

	i = 0;
	x = (char)c;
	d = s;
	while (s[i] != '\0')
	{
		if (s[i] == x)
			return (char*)d;
		d++;
		i++;
	}
	if (c == 0)
		return ((char*)(s + i));
	return (NULL);
}
