/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:40:09 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/04 20:22:39 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define g_buffer_SIZE 4096
int		get_next_line(int fd, char **line);
char	*get_copy(char **stock, char **line, int fd);
char	*get_go(char *g_buffer, char **line, int ret);
int		fr_ptr(char *g_buffer, int ret);

#endif
