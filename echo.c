/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 08:37:36 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/12 13:46:30 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
	{
		ft_putchar_fd('\n', 1);
		return (1);
	}
	if (ft_strncmp(argv[1], "-n", 2) == 0)
	{
		i = 2;
		while (i < argc)
			ft_putstr_fd(argv[i++], 1);
	}	
	else
	{
		i = 1;
		while (i < argc)
			ft_putstr_fd(argv[i++], 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}
