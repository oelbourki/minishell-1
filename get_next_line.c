/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:24:10 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/28 15:23:58 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			check(char **left, char **line, char *buffer)
{
	char	*p;
	char	*tmp;

	if (*left == NULL)
		return (0);
	if ((p = ft_strchr(*left, '\n')))
	{
		*p = '\0';
		*line = ft_strjoin(*line, *left);
		tmp = *left;
		*left = ft_strdup(++p);
		free(tmp);
		tmp = NULL;
		free(buffer);
		buffer = NULL;
		return (1);
	}
	tmp = *line;
	*line = ft_strdup(*left);
	free(tmp);
	tmp = NULL;
	free(*left);
	(*left) = NULL;
	return (0);
}

static int			body(char **p, char **line, char *buffer, char **left)
{
	char *tmp;

	**p = '\0';
	*line = ft_strjoin(*line, buffer);
	tmp = *left;
	*left = ft_strdup(++(*p));
	free(tmp);
	tmp = NULL;
	free(buffer);
	buffer = NULL;
	return (1);
}

int					get_next_line(int fd, char **line)
{
	char			*p;
	static char		*left[4864];
	int				r;
	char			*buffer;

	if (fd < 0 || read(fd, NULL, 0) != 0 ||
	(line == NULL) || !(*line = ft_strdup("")) ||
	(BUFFER_SIZE < 0) || !(buffer = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (check(&left[fd], line, buffer))
		return (1);
	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r] = '\0';
		if ((p = ft_strchr(buffer, '\n')) && body(&p, line, buffer, &left[fd]))
			return (1);
		*line = ft_strjoin(*line, buffer);
	}
	if (r <= 0 || BUFFER_SIZE == 0)
	{
		free(left[fd]);
		free(buffer);
		return (0);
	}
	return (1);
}
