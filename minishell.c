/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 22:27:39 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/11 12:52:23 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	char	*command;
	char	*tmp;
	int		P_id;

	while (1)
	{
		ft_putstr_fd("root@e2r10p5:~# ", 1);
		get_next_line(1, &command);
		tmp = command;
		command = ft_strtrim(command, " \t");
		free(tmp);
		char **ag = ft_split(command, ' ');
		if ((P_id = fork()) < 0)
		{
			free(command);
			write(2, "Error in Building process\n", 26);
			return (-1);
		}
		else if (P_id == 0)
				execve(ag[0], &ag[0], NULL);
		else
			wait(NULL);
		free(command);
	}
	return (0);
}
