//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:30:52 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/21 15:43:02 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
<<<<<<< HEAD
	t_env		*environt;
=======
>>>>>>> kirwa
	t_command	*command;
	char		*tmp;
	char		*line;
	int			ret;

	(void)argc;
	(void)argv;
	environt = NULL;
	command = NULL;
	environt = copyEnvp(envp);
	tmp = ft_strdup("");
	while (1)
	{
		if (tmp[0] == 0)
			ft_putstr_fd("root@e120e15p3# ", 1);
		ret = get_next_line(0, &line);
		if (ret == 0)
		{
			if (line[0] != '\0' || tmp[0] != '\0')
			{
				tmp = ft_strjoin(tmp, line);
				free(line);
				continue ;
			}
			else
				exit(-1);
		}
		line = ft_strjoin(tmp, line);
		free(tmp);
		tmp = ft_strdup("");
		command = parse(line, command);
		command = double_simple_qoute(command, environt);
<<<<<<< HEAD
		print_command(command);
=======
		// print_command(command);
		the_main(command);
>>>>>>> kirwa
		ft_lstclear_command(&command);
		free(line);
	}
}
