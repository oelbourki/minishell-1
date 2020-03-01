/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 08:44:20 by ibaali            #+#    #+#             */
/*   Updated: 2020/03/01 11:33:11 by ibaali           ###   ########.fr       */
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

	g_home = var("HOME");
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
		free(g_home);
		exit(0);
	}
	return (0);
}

void	nrom_color_prompt(char **prompt)
{
	ft_putstr_fd("\033[1;32m", 1);
	ft_putstr_fd(*prompt, 1);
	free(*prompt);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd(" on ", 1);
	ft_putstr_fd("\033[1;31m", 1);
	ft_putstr_fd(" master!", 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("\033[0;36m", 1);
	ft_putstr_fd(" ⌚ 15:13:47", 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("\n$ ", 1);
}

void	color_prompt(void)
{
	char	buff[1000];
	char	*path;
	int		slach;
	int		i;
	char	*prompt;

	slach = 0;
	i = 0;
	ft_memset(buff, 0, 1000);
	path = getcwd(buff, 1000);
	if (ft_strncmp(path, g_home, ft_strlen(g_home)) == 0)
	{
		while (path[i] != '\0')
		{
			if (path[i] == '/')
				slach += 1;
			if (slach == 3)
				break ;
			i++;
		}
		prompt = ft_strjoin("~", path + i);
	}
	else
		prompt = ft_strdup(path);
	nrom_color_prompt(&prompt);
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
		// g_command = parse_error(&g_command);
		print_command(g_command);
		// the_main(g_command);
		ft_lstclear_command(&g_command);
		free(g_line);
	}
}
