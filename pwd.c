/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 08:40:11 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/11 11:28:20 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(int argc, char **argv)
{
	char	*path;

	(void)argv;
	if (argc > 1)
	{
		write(1, "pwd: too many arguments\n", 24);
		return (-1);
	}
	if ((path = (char*)malloc(MAX_PATH + 1)) == NULL)
		return (-1);
	path = getcwd(path, MAX_PATH);
	ft_putstr_fd(path, 1);
	ft_putchar_fd('\n', 1);
	free(path);
}
