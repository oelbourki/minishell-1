/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 22:25:29 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/13 21:40:57 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#define MAX_PATH 1024
#define EXIST 1
#define NOT_EXIST 0

typedef struct  s_cmd
{
    char            **ag;
    int             red_create_output;
    int             red_append_output;
    int             red_input;
    char            *file_input;
    char            *file_output;
    struct  s_cmd   *next;
}               t_cmd;


int		skip_white_space(char *str, int i);
int		is_this_command(char *line, char *command);

#endif
