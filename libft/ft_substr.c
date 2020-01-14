/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:49:45 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/20 15:34:39 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;

	index = 0;
	if (!s)
		return (NULL);
	sub = (char*)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		sub[0] = '\0';
		return (sub);
	}
	while (index < len && s[start] != '\0')
		sub[index++] = s[start++];
	sub[index] = '\0';
	return (sub);
}
