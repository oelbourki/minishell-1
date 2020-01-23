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
	t_env		*environt;
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
		ret = get_next_line(0, &line);
		line = ft_strjoin(tmp, line);
		command = parse(line, command);
		command = double_simple_qoute(command, environt);
		print_command(command);
		if (ret == 0)
		{
			if (line[0] != '\0')
			{
				tmp = ft_strdup(line);
				free(line);
				continue ;
			}
			else
				exit(-1);
		}
		free(line);
	}
}
