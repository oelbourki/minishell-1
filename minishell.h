/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:25:06 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/22 22:06:55 by ibaali           ###   ########.fr       */
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
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>

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

t_command	*ft_lstnew_command(char *str, int what);
void		ft_lstadd_back_command(t_command **alst, t_command *new);
t_env  		*copyEnvp(char **envp);
t_command	*parse(char *line, t_command *cmd);
t_command	*double_simple_qoute(t_command *cmd, t_env *environt);

void		print_list(t_env *ls);
void	print_command(t_command *command);

#endif
