/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:28:40 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/14 18:28:41 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
int fd_p[2];

typedef struct s_cmd
{
    char **main_cmd;
    int simple;
    int pipe;
    char *file;
    int red;
}t_cmd;
const static char *commands[] = {
    "echo",
    "cd",
    "pwd",
    "export",
    "unset",
    "env",
    "exit",
};

const static char *redirection[] = {
    "<",
    ">",
    ">>",
};

const static char *not[] = {
    "|",
    ";",
};

static int i;
static int j;
typedef struct s_env
{
    char *data;
    struct s_env *next;
}t_env;

