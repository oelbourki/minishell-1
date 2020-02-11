/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 08:44:20 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/11 15:00:01 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*g_a_free;

void	minishell(int argc, char **argv, char **envp, char **tmp)
{
	(void)argc;
	(void)argv;
	g_environ = envp;
	g_environt = NULL;
	g_command = NULL;
	g_environt = copyenvp(envp);
	signal(SIGINT, signal_int);
	signal(SIGQUIT, signal_quit);
	*tmp = ft_strdup("");
}

int		control_d(char **line, char **tmp)
{
	if ((*line)[0] != '\0' || (*tmp)[0] != '\0')
	{
		g_a_free = *tmp;
		*tmp = ft_strjoin(*tmp, *line);
		free(g_a_free);
		free(*line);
		return (-1);
	}
	else
	{
		ft_putstr_fd("exit\n", 1);
		free(*tmp);
		free(*line);
		ft_lstclear_command(&g_command);
		ft_lstclear_env(&g_environt);
		ft_lstclear_env(&g_variables);
		exit(0);
	}
	return (0);
}

void	color_prompt(void)
{
	ft_putstr_fd("\033[1;31m", 1);
	ft_putstr_fd("root@e120e15p3# ", 1);
	ft_putstr_fd("\033[0m", 1);
}

int		main(int argc, char **argv, char **envp)
{
	int			ret;

	minishell(argc, argv, envp, &g_tmp);
	while (1)
	{
		g_pid = 0;
		g_to_skip = 0;
		if (g_tmp[0] == 0)
			color_prompt();
		ret = get_next_line(0, &g_line);
		if (ret == 0)
			if (control_d(&g_line, &g_tmp) == -1)
				continue ;
		g_a_free = g_line;
		g_line = ft_strjoin(g_tmp, g_line);
		free(g_a_free);
		free(g_tmp);
		g_tmp = ft_strdup("");
		g_command = parse(g_line, g_command);
		g_command = double_simple_qoute(g_command);
		g_command = parse_error(&g_command);
		print_command(g_command);
		printf("---------------------------------------\n");
		the_main(g_command);
		ft_lstclear_command(&g_command);
		free(g_line);
	}
}
