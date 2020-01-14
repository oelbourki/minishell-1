/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:04:09 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/13 20:04:47 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_nee;

	len_nee = 0;
	i = 0;
	while (needle[len_nee] != '\0')
		len_nee++;
	if (len_nee == 0)
		return ((char*)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0] &&
				ft_strncmp(haystack + i, needle, len_nee) == 0 &&
				((len_nee + i) < len + 1))
		{
			return ((char*)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
