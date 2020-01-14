/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:14:03 by ibaali            #+#    #+#             */
/*   Updated: 2019/10/19 21:32:10 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned	char	*temp;

	temp = (unsigned char*)b;
	while (len--)
	{
		*temp = (unsigned char)c;
		temp++;
	}
	return (b);
}
