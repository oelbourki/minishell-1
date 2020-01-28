/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:25:06 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/28 08:56:42 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
# define MINISHELL
# define REDIN 0
# define REDOUT 1
# define DOUBLEREDOUT 2
# define SEMICOL 3
# define COMMAND 4
# define STRING 5
# define PIPE 6
# define DOLLAR 7
# define SIMDOUTE 8
# define DBLDOUTE 9
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
#include "libftprintf.h"
/* * * * * * */
const static char *commands[] = {
    "echo",
    "cd",
    "pwd",
    "export",
    "unset",
    "env",
    "exit",
    "var",
};

int  is_cmd(char * sem);
int   ft_exx(char **arg,int first,int last,int input);
int cd(char *s);
int     pwd();
int   export(char **arg);
void    ft_free(char **arg);
void    ft_free_star(char **arg);
int		unset(char **arg);
char		*var(char *s);
void	signal_x(int f);


/* * * * */



typedef	struct	s_command
{
	char	*str;
	int		what;
	struct	s_command	*next;
}				t_command;

typedef	struct	s_env
{
	char	*variable;
	char	*value;
	struct	s_env	*next;
}				t_env;

t_env		*environt;
t_env		*variables;
int	env_declarex(t_env *ls);
int	env_var(t_env *ls);
t_command	*ft_lstnew_command(char *str, int what);
void		ft_lstadd_back_command(t_command **alst, t_command *new);
t_env  		*copyEnvp(char **envp);
t_command	*parse(char *line, t_command *cmd);
t_command	*double_simple_qoute(t_command *cmd, t_env *environt);
int		    env(t_env *ls);
void	    print_command(t_command *command);
void	    ft_lstclear_command(t_command **alst);
int         the_main(t_command *head);
t_command   **get_semi(t_command *head,int *N);
t_command   **get_pipe(t_command *head,int *n);
void	ft_lstadd_back_envp(t_env **alst, t_env *new);


void    push_back_ex(t_env **head,t_env *data,char **s);
#endif
