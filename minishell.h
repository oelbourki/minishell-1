/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:25:06 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/21 19:55:24 by ibaali           ###   ########.fr       */
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
# define OPTION 7
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


t_env  *copyEnvp(char **envp);
void	print_list(t_env *ls);

#endif
