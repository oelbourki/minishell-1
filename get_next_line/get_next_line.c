/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:29:18 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/11 08:18:03 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_copy(char **stock, char **line, int fd)
{
	char	*remember;
	char	*tmp;
	char	*res;

	if ((remember = ft_strchr(stock[fd], '\n')) != NULL)
	{
		*remember = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, stock[fd]);
		free(tmp);
		res = ft_strdup(remember + 1);
		free(stock[fd]);
		return (res);
	}
	tmp = *line;
	*line = ft_strjoin(*line, stock[fd]);
	free(tmp);
	free(stock[fd]);
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	static	char	*stock[300];
	int				ret;
	char			*buffer;
	char			*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 0 || !(buffer =
	(char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	*line = ft_strdup("");
	stock[fd] = (stock[fd] == NULL) ? NULL : get_copy(stock, line, fd);
	if (stock[fd] != NULL)
		return (fr_ptr(buffer, 1));
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if ((stock[fd] = get_go(buffer, line, ret)) != NULL)
			return (fr_ptr(buffer, 1));
		tmp = *line;
		*line = ft_strjoin(*line, buffer);
		free(tmp);
	}
	free(stock[fd]);
	return (fr_ptr(buffer, ret));
}

char	*get_go(char *buffer, char **line, int ret)
{
	char	*stock;
	char	*res;
	char	*tmp;

	buffer[ret] = '\0';
	if ((stock = ft_strchr(buffer, '\n')) != NULL)
	{
		*stock = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buffer);
		free(tmp);
		res = ft_strdup(stock + 1);
		return (res);
	}
	return (NULL);
}

int		fr_ptr(char *buffer, int ret)
{
	free(buffer);
	return (ret);
}
