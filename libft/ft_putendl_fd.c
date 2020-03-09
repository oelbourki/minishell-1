/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:30:13 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/10 22:30:19 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putendl_fd(char *s, int fd)
{
	char		n;
	int			l;
	const char	*h;

	if (s != NULL)
	{
		h = (const char*)s;
		n = '\n';
		l = ft_strlen(h);
		write(fd, s, l);
		write(fd, &n, 1);
	}
}
