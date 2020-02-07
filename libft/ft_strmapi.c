/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:34:09 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 22:34:11 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			l;
	char			*x;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	x = (char*)malloc((l + 1) * sizeof(char));
	if (x == NULL)
		return (NULL);
	while (i < l)
	{
		x[i] = (*f)(i, s[i]);
		i++;
	}
	x[i] = '\0';
	return (x);
}
