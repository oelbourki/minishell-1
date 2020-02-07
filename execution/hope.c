/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hope.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:51:56 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/07 18:34:55 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	help_the_main(void)
{
	while (g_var.j < g_var.n - 1)
	{
		g_p = 1;
		g_var.arg = convert(g_var.pipe[g_var.j]);
		g_var.input = ft_exx(g_var.arg, g_var.first, 0, g_var.input);
		ft_free_star(g_var.arg);
		g_var.first = 0;
		g_var.j++;
	}
}

int		the_main(t_command *head)
{
	init_t_vars(&g_var);
	g_var.semi = get_semi(head, &g_var.m);
	while (g_var.i < g_var.m)
	{
		if (g_var.semi[g_var.i] != NULL)
		{
			g_var.j = 0;
			g_var.first = 1;
			g_var.pipe = get_pipe(g_var.semi[g_var.i], &g_var.n);
			help_the_main();
			g_var.arg = convert(g_var.pipe[g_var.j]);
			ft_exx(g_var.arg, g_var.first, 1, g_var.input);
			ft_free_star(g_var.arg);
			free(g_var.pipe);
			g_p = 0;
		}
		g_var.i++;
	}
	free(g_var.semi);
	return (0);
}
