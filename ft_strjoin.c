/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:32:52 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 22:32:55 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*copy(char const *s1, char const *s2, char *x)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		x[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		x[i++] = s2[j];
		j++;
	}
	x[i] = '\0';
	return (x);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*x;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup((char*)s2));
	if (s2 == NULL && s1 != NULL)
		return (ft_strdup((char*)s1));
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	x = (char*)malloc(l1 + l2 + 1);
	if (x == NULL)
		return (NULL);
	return (copy(s1, s2, x));
}
