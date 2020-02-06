/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 08:44:20 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/06 12:37:14 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	char		*tmp;
	char		*a_free;
	char		*line;
	int			ret;

	(void)argc;
	(void)argv;
	g_pid = 0;
	g_environt = NULL;
	g_command = NULL;
	g_environt = copyenvp(envp);
	tmp = ft_strdup("");
	signal(SIGINT, signal_int);
	signal(SIGQUIT, signal_quit);
	while (1)
	{
		g_to_skip = 0;
		if (tmp[0] == 0)
			ft_putstr_fd("root@e120e15p3 # ", 1);
		ret = get_next_line(0, &line);
		if (ret == 0)
		{
			if (line[0] != '\0' || tmp[0] != '\0')
			{
				a_free = tmp;
				tmp = ft_strjoin(tmp, line);
				free(a_free);
				free(line);
				continue ;
			}
			else
			{
				ft_putstr_fd("exit\n", 1);
				free(tmp);
				free(line);
				ft_lstclear_command(&g_command);
				ft_lstclear_env(&g_environt);
				exit(0);
			}
		}
		a_free = line;
		line = ft_strjoin(tmp, line);
		free(a_free);
		free(tmp);
		tmp = ft_strdup("");
		/* you need to remove this free */
		// free(tmp);
		g_command = parse(line, g_command);
		g_command = double_simple_qoute(g_command, g_environt);
		// print_command(g_command);
		the_main(g_command);
		ft_lstclear_command(&g_command);
		// ft_lstclear_env(&g_environt);
		free(line);
	}
}
