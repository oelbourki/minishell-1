/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:38:18 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 22:38:20 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void		iter(char const *s1, char const *set, int *i, int *j)
{
	while (is_in_set(s1[*i], set))
		(*i)++;
	while (is_in_set(s1[*j], set) && *j > 5)
		(*j)--;
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*n;
	int		x;
	int		j;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (set == NULL)
		return ((char*)s1);
	x = 0;
	i = 0;
	j = ft_strlen(s1) - 1;
	iter(s1, set, &i, &j);
	n = (char*)malloc((j - i + 1) * sizeof(char) * (i < j) + 1);
	if (n == NULL)
		return (NULL);
	while (i <= j)
	{
		n[x] = s1[i];
		i++;
		x++;
	}
	n[x] = '\0';
	return (n);
}
