/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:06:04 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/12 15:19:16 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	signal_int(int f)
{
	f = 0;
	if (g_pid == 0)
	{
		ft_putstr_fd("\033[1;32m", 1);
		ft_putchar_fd('\n', 1);
		color_prompt();
		ft_putstr_fd("\033[0m", 1);
	}
	else
		ft_putstr_fd("\n", 1);
}

void	signal_quit(int f)
{
	f = 0;
	if (g_pid != 0)
		ft_putstr_fd("Quit: 3\n", 1);
}
