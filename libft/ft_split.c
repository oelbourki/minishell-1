/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 08:08:09 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/07 16:16:41 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_repeat(char const *s, char c, int i)
{
	while (s[i + 1] == c)
		i++;
	return (i);
}

static int	nb_wd(char const *s, char c)
{
	int		i;
	int		wd;

	i = 0;
	wd = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			wd++;
			i = is_repeat(s, c, i);
		}
		i++;
	}
	if (s == NULL)
		return (0);
	return ((s[i - 1] == c) ? wd : wd + 1);
}

static int	nb_ch(char const *s, char c)
{
	int		i;
	int		ch;
	int		max;

	i = 0;
	ch = 0;
	max = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		ch += 1;
		if (s[i] == c)
		{
			i = is_repeat(s, c, i);
			if (ch > max)
			{
				max = ch;
				ch = 0;
			}
		}
		i++;
	}
	return ((ch > max) ? ch : max - 1);
}

static char	**fill_range(char **range, char const *s, char c, int wd)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	while (i < wd)
	{
		while (s[k] == c)
			k++;
		j = 0;
		while (s[k] != c && s[k] != '\0')
		{
			range[i][j] = s[k++];
			j++;
		}
		range[i][j] = '\0';
		i++;
	}
	range[wd] = NULL;
	return (range);
}

char		**ft_split(char const *s, char c)
{
	char	**range;
	int		i;
	int		wd;

	if (s == NULL)
		return (NULL);
	i = 0;
	wd = nb_wd(s, c);
	range = (char**)malloc((wd + 1) * sizeof(char*));
	if (range == NULL)
		return (NULL);
	while (i < wd)
	{
		range[i++] = (char*)malloc(nb_ch(s, c) * sizeof(char) + 1);
		if (range[i - 1] == NULL)
		{
			while (--i >= 0)
				free(range[i]);
			free(range);
			return (NULL);
		}
	}
	range = fill_range(range, s, c, wd);
	return (range);
}