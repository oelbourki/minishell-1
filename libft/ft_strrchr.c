/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:25:52 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/15 17:35:52 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	ch;
	char	*tmp;
	char	*ptr_res;

	tmp = (char*)str;
	ptr_res = NULL;
	ch = (char)c;
	while (*tmp != '\0')
	{
		if (*tmp == ch)
			ptr_res = tmp;
		tmp++;
	}
	if (ch == '\0')
		return (tmp);
	return (ptr_res);
}
