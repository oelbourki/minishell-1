/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:06:04 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/06 18:02:11 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	signal_int(int f)
{
	if (g_pid == 0)
		ft_putstr_fd("\nroot@e120e15p3 # ", 1);
	else
		ft_putstr_fd("\n", 1);
}

void	signal_quit(int f)
{
	f = 0;
}
