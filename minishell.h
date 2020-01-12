/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 22:25:29 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/11 14:11:35 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#define MAX_PATH 1024
#define EXIST 1
#define NOT_EXIST 0

int		skip_white_space(char *str, int i);
int		is_this_command(char *line, char *command);

#endif
