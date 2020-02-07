/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:27:01 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 19:27:03 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char		x;
	int					i;
	int					l;

	i = 0;
	x = (unsigned char)c;
	l = ft_strlen(s);
	if (c == '\0')
		return ((char*)(s + l));
	while (l > 0)
	{
		if (s[l] == x)
		{
			return (char*)(s + l);
		}
		l--;
	}
	if (s[0] == x)
		return (char*)s;
	return (NULL);
}
