/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:39:03 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 22:39:05 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sub_(void)
{
	char *sub;

	sub = malloc(1);
	if (sub == NULL)
		return (NULL);
	sub[0] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;
	size_t		x;
	size_t		f;

	if (s == NULL || start > ft_strlen(s))
		return (sub_());
	sub = (char*)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	x = (ft_strlen(s) - start) * (len != 0);
	if (x >= len)
		f = len;
	else
		f = x;
	i = 0;
	while (i < f)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
