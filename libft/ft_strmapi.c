/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:38:07 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/19 17:35:14 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*dst;
	char				*src;
	unsigned	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	src = (char*)s;
	dst = (char*)malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (dst == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = f(i, src[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
