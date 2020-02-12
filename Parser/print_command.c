/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:08:28 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/12 16:08:56 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		print_command(t_command *g_command)
{
	while (g_command != NULL)
	{
		ft_printf("\nnode = [%s] index = ", g_command->str);
		if (g_command->what == DOUBLEREDOUT)
			ft_printf("DOUBLEREDOUT");
		else if (g_command->what == REDIN)
			ft_printf("REDIN\n");
		else if (g_command->what == REDOUT)
			ft_printf("REDOUT\n");
		else if (g_command->what == SEMICOL)
			ft_printf("SEMICOL\n");
		else if (g_command->what == COMMAND)
			ft_printf("COMMAND\n");
		else if (g_command->what == STRING)
			ft_printf("STRING\n");
		else if (g_command->what == PIPE)
			ft_printf("PIPE\n");
		g_command = g_command->next;
	}
	ft_printf("\n");
}
