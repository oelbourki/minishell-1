/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:28:40 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/26 09:58:31 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <sys/stat.h>

# define REDIN 0
# define REDOUT 1
# define DOUBLEREDOUT 2
# define SEMICOL 3
# define COMMAND 4
# define STRING 5
# define PIPE 6

typedef struct  s_command
{
    char    *str;
    int     what;
    struct  s_command *next;
}      t_command;
// int fd_p[2];


int ll;
typedef struct s_cmd
{
    char **argv;
    int simple;
    int pipe;
    char *file;
    int red;
}t_cmd;
typedef struct s_slot
{
    char *key;
    char *value;
    struct s_slot *next;
}t_slot;
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
    NULL,
};

static int i;
static int j;
typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
}t_env;
int cd(char *s);
int     pwd();
t_command **get_semi(t_command *head,int *N);
t_command **get_pipe(t_command *head,int *n);
void    push_back1(t_command **head,char *str,int what);
t_command   *creat_(char *str,int what);
void    print(t_command *head);
t_cmd *creat_cmd(t_command **head);
int  is_cmd(char * sem);
int   ft_exx(char **arg,int first,int last,int input);

int   ft_ex(char **arg,char **env);






#endif