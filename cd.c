/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 09:50:04 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/11 12:46:42 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (argc > 2)
	{
		ft_putstr_fd("cd: string not in pwd: ", 1);
		ft_putstr_fd(argv[1], 1);
		return (-1);
	}
	if (chdir(argv[1]) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}
