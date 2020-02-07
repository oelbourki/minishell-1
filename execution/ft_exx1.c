/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exx1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:32:43 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/06 18:02:11 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		end(int last, int input, int fd[2])
{
	if (last == 1)
		close(fd[0]);
	if (input != 0)
		close(input);
	close(fd[1]);
	return (fd[0]);
}

void	dupx(int first, int last, int input, int fd[2])
{
	if (first == 1 && last == 0 && input == 0)
		dup2(fd[1], 1);
	else if (first == 0 && last == 0 && input != 0)
	{
		dup2(input, 0);
		dup2(fd[1], 1);
	}
	else
		dup2(input, 0);
	if (g_multi_redout == 1)
		dup2(g_out_fd, 1);
	if (g_mul_redin == 1)
		dup2(g_in_fd, 0);
}
