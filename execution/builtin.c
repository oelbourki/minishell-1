/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:03:33 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/06 18:02:11 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		ft_strlcpy(g_buff, s, sizeof(g_buff));
}

int		cd(char *s)
{
	char *p;
	char *h;
	char *tmp;

	ft_memset(g_buff, 0, 100);
	h = var("HOME");
	if (h != NULL)
	{
		tmp = h;
		h = ft_strjoin(h, "/");
		free(tmp);
	}
	else
		return (ft_print("bash: cd: HOME not set\n"));
	if (s == NULL)
		s = h;
	help_cd(s, h);
	if (chdir(g_buff) != 0)
	{
		printf("cd: %s: No such file or directory\n", g_buff);
		g_status = 1;
		return (0);
	}
	return (1);
}

int		pwd(int fd)
{
	char g_buffer[1000];
	char *h;

	ft_memset(g_buffer, 0, 100);
	h = getcwd(g_buffer, 100);
	if (h != NULL)
	{
		write(fd, g_buffer, strlen(g_buffer));
		write(fd, "\n", 1);
	}
	else
		g_status = 1;
	return (1);
}
