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
	char			*line;

	environt = NULL;
	command = NULL;
	environt = copyEnvp(envp);
	print_list(environt);
	// get_next_line(0, &line);
	// cmd = parse(line, cmd);
}
