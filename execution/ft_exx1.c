/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exx1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:32:43 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 15:44:10 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	closeall(int i)
{
	int f;

	f = 0;
	while (f < i)
	{
		close(g_dff[f][0]);
		close(g_dff[f][1]);
		f++;
	}
}

void	help_dupx(int i)
{
	if (g_multi_redout == 1)
	{
		dup2(g_out_fd, 1);
		close(g_dff[i][1]);
	}
	if (g_mul_redin == 1)
	{
		dup2(g_in_fd, 0);
		close(g_dff[i - 1][0]);
	}
}

void	dupx(int i, int n)
{
	help_dupx(i);
	if (i == 0)
	{
		close(g_dff[i][0]);
		dup2(g_dff[i][1], 1);
	}
	else if (i == n - 1)
	{
		close(g_dff[i - 1][1]);
		dup2(g_dff[i - 1][0], 0);
		closeall(i - 1);
	}
	else if (i >= 0 && i != 0 && i != n - 1)
	{
		dup2(g_dff[i - 1][0], STDIN_FILENO);
		close(g_dff[i][0]);
		close(g_dff[i - 1][1]);
		closeall(i - 1);
		dup2(g_dff[i][1], STDOUT_FILENO);
	}
}
