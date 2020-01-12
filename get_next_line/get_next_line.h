/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:40:09 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/11 08:37:00 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int		get_next_line(int fd, char **line);
char	*get_copy(char **stock, char **line, int fd);
char	*get_go(char *buffer, char **line, int ret);
int		fr_ptr(char *buffer, int ret);

#endif

#ifndef	BUFFER_SIZE
#define BUFFER_SIZE 4096

#endif
