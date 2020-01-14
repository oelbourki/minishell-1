/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:09:19 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/19 21:29:26 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	i = 0;
	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < n && tmp1[i] == tmp2[i] && tmp1[i] != '\0' && tmp2[i] != '\0')
		i++;
	if (i == n)
		return (tmp1[i - 1] - tmp2[i - 1]);
	return (tmp1[i] - tmp2[i]);
}
