/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:32:33 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/07 11:56:20 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		count(char **g_argv)
{
	int i;

	i = 0;
	while (g_argv[i])
		i++;
	return (i);
}

void	print_echo(char **g_argv, int i, int argc)
{
	while (g_argv[i])
	{
		write(1, g_argv[i], strlen(g_argv[i]));
		if (i != argc - 1)
			write(1, " ", 1);
		i++;
	}
}

int		echo(char **g_argv)
{
	int argc;
	puts("-------");
	argc = count(g_argv);
	if (argc == 1)
		write(1, "\n", 1);
	else if (argc > 2 && ft_strcmp(g_argv[1], "-n") == 0)
		print_echo(g_argv, 2, argc);
	else if (argc == 2 && ft_strcmp(g_argv[1], "-n") == 0)
		return (0);
	else
	{
		print_echo(g_argv, 1, argc);
		write(1, "\n", 1);
	}
	return (0);
}
