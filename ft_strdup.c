/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:11:50 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 19:11:56 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
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
