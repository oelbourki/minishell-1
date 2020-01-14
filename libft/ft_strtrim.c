/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:23:28 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/19 20:07:47 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	deb_index(char const *s1, char const *set)
{
	int		deb;

	deb = 0;
	while (s1[deb] != '\0' && (ft_strchr(set, s1[deb]) != NULL))
		deb++;
	return (deb);
}

static	int	fin_index(char const *s1, char const *set, int len_s1)
{
	int		fin;
	int		deb;

	fin = len_s1;
	deb = deb_index(s1, set);
	while (ft_strchr(set, s1[fin - 1]) != NULL && fin > deb)
		fin--;
	return (fin);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		index_deb;
	int		index_fin;
	int		i;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	index_deb = 0;
	i = 0;
	index_deb = deb_index(s1, set);
	index_fin = fin_index(s1, set, ft_strlen(s1));
	if (index_deb == (int)ft_strlen(s1))
	{
		str = (char*)malloc(1);
		str[0] = '\0';
		return (str);
	}
	str = (char*)malloc((index_fin - index_deb) + 1);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (index_fin - index_deb + 1));
	while (index_fin > index_deb)
		str[i++] = s1[index_deb++];
	return (str);
}
