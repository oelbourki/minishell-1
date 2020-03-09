/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:03:33 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 16:17:42 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	help_cd(char *s, char *h)
{
	if (s[0] == '~' && s[1] == '/')
	{
		ft_strlcpy(g_buff, h, sizeof(g_buff));
		free(h);
		ft_strlcat(g_buff, s + 2, sizeof(g_buff));
	}
	else if (s[0] == '~')
	{
		ft_strlcpy(g_buff, h, sizeof(g_buff));
		free(h);
		ft_strlcat(g_buff, s + 1, sizeof(g_buff));
	}
	else
	{
		ft_strlcpy(g_buff, s, sizeof(g_buff));
		free(h);
	}
}

int		cd(char *s)
{
	char *h;
	char *tmp;

	ft_memset(g_buff, 0, 100);
	tmp = var("HOME");
	if (tmp != NULL)
	{
		h = ft_strjoin(tmp, "/");
		free(tmp);
		tmp = NULL;
	}
	else
		return (ft_print("bash: cd: HOME not set\n"));
	if (s == NULL)
		s = h;
	help_cd(s, h);
	if (chdir(g_buff) != 0)
	{
		ft_printf("cd: %s: No such file or directory\n", g_buff);
		g_status = 1;
		return (0);
	}
	return (((g_status = 0) == 0));
}

int		pwd(int fd)
{
	char g_buffer[1000];
	char *h;

	ft_memset(g_buffer, 0, 100);
	h = getcwd(g_buffer, 100);
	if (h != NULL)
	{
		write(fd, g_buffer, ft_strlen(g_buffer));
		write(fd, "\n", 1);
	}
	else
		g_status = 1;
	g_status = 0;
	return (1);
}
