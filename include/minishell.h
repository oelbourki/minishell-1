/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:25:06 by ibaali            #+#    #+#             */
/*   Updated: 2020/03/09 10:34:52 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
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
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "libft.h"

typedef	struct			s_command
{
	char				*str;
	int					what;
	struct s_command	*next;
}						t_command;

typedef	struct			s_env
{
	char				*variable;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef	struct			s_vars
{
	int					n;
	int					m;
	t_command			**semi;
	int					i;
	int					j;
	int					first;
	t_command			**pipe;
	int					input;
	char				**arg;
	int					g_pipe;
}						t_vars;

static char				*g_commands[] = {
	"echo",
	"cd",
	"pwd",
	"export",
	"unset",
	"env",
	"exit",
	"var",
};
char					*g_s;
int						g_dff[1000][2];
char					*g_tmp;
char					*g_line;
int						g_pid;
int						g_multi_redout;
int						g_status;
int						g_p;
int						g_mul_redin;
int						g_out_fd;
int						g_in_fd;
int						g_fd[2];
struct stat				g_buffer;
char					*g_home;
char					**g_argv;
char					g_buff[100];
t_command				*g_counter;
t_vars					g_var;
t_env					*g_environt;
t_env					*g_variables;
int						g_to_skip;
t_command				*g_command;
int						g_start;
char					**g_environ;

int						to_lower(t_command **counter);
int						error(void);
void					dupx(int first, int last);
int						end(int last, int input, int fd[2]);
int						ft_free(char **arg);
int						ft_print(char *s);
int						ft_free_star(char **arg);
int						unset(char **arg);
char					*var(char *s);
void					signal_x(int f);
void					ft_free_void_star(void **arg);
void					ft_free_void(void **arg);
void					signal_int(int f);
char					*ft_strcat(char *dest, char *src, int *j);
char					*ft_strcpy(char *dest, char *src);
void					signal_quit(int f);
int						is_string(char *s);
int						echo(char **g_argv);
int						do_someout(t_command **head);
int						do_someout_1(t_command **head);
int						do_somein(t_command **head);
int						do_somein_1(t_command **head);
char					*path(char *f);
int						cd1(char *s);
void					init_t_vars(t_vars *var);
void					push_back1(t_command **head, char *str, int what);
int						ft_strcmp(const char *s1, const char *s2);
char					**help_convert1(t_command *counter);
char					**convert(t_command *head);
void					push_back_ex(t_env **head, t_env *data, char **s);
int						env_var(t_env *ls);
int						is_cmd(char *sem);
int						ft_exx(char **arg, int first, int last);
int						cd(char *s);
int						pwd();
int						export(char **arg);
int						env_declarex(t_env *ls);
t_command				*ft_lstnew_command(char *str, int what);
void					ft_lstadd_back_command(t_command **alst,
													t_command *new);
t_env					*copyenvp(char **envp);
t_command				*parse(char *line, t_command *cmd);
t_command				*double_simple_qoute(t_command *cmd);
int						env(t_env *ls);
void					print_command(t_command *g_command);
void					ft_lstclear_command(t_command **alst);
int						the_main(t_command *head);
t_command				**get_semi(t_command *head, int *n);
t_command				**get_pipe(t_command *head, int *n);
void					ft_lstclear_env(t_env **alst);
t_command				*pipe_rin_semicol(int *i, int *is_cmd,
											char *tmp, t_command *cmd);
t_command				*putspacecmd(int *fin, int *is_cmd,
											char *tmp, t_command *cmd);
t_command				*rediriction_out(int *i, int *is_cmd,
											char *tmp, t_command *cmd);
char					*put_value_of_dollar(char *str, int *i);
char					*back_slach(char *new, char *str, int *i, int *j);
t_command				*parse_error(t_command **cmd);
void					free_all(void);
void					color_prompt(void);
void					closeall(int i);
void					help_double_simple_qoute(t_command *tmp, char **new,
														int i, int j);
int						norm_double_simple_qoute(int *i, int *j,
												t_command *tmp, char **new);
void					free_tmp_strdup(t_command *tmp, char *new);
int		ft_free_star_ok(char **arg);
#endif
