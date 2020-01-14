/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:25:45 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 19:25:47 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*c;

	if (h == NULL && len == 0 && n != NULL)
		return (NULL);
	c = h;
	i = 0;
	while (*h != '\0' && i < len)
	{
		j = 0;
		c = h;
		while (n[j] == c[j] && (i + j) < len && c[j] != '\0')
			j++;
		if (n[j] == '\0')
			return ((char*)h);
		h++;
		i++;
	}
	if (n[0] == '\0')
		return ((char*)h);
	return (NULL);
}
