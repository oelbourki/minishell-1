/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:23:08 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/28 15:16:48 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *s)
{
	size_t i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(const char *s1)
{
	int		l;
	int		i;
	char	*h;

	i = 0;
	l = ft_strlen(s1);
	h = (char*)malloc((l + 1) * sizeof(char));
	if (h == NULL)
		return (NULL);
	while (i < l)
	{
		h[i] = s1[i];
		i++;
	}
	h[i] = '\0';
	return (h);
}

char				*ft_strchr(const char *s, int c)
{
	char		x;
	int			i;
	const char	*d;

	if (s == NULL)
		return (NULL);
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

static char			*copy(char const *s1, char const *s2, char *x)
{
	int			i;
	int			j;
	char		*tmp;

	tmp = (char*)s1;
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
	free((void*)tmp);
	tmp = NULL;
	return (x);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	int			l1;
	int			l2;
	char		*x;

	if (s1 == NULL && s2 != NULL)
		return ((char*)s2);
	if (s2 == NULL && s1 != NULL)
		return ((char*)s1);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	x = (char*)malloc(l1 + l2 + 1);
	if (x == NULL)
		return (NULL);
	return (copy(s1, s2, x));
}
