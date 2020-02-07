/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:51:23 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/07 15:23:22 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*help_path(char *s, char *f)
{
	char	**path;
	int		i;
	char	*tmp;

	i = 0;
	path = ft_split(s, ':');
	while (path != NULL && path[i])
	{
		tmp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		ft_free(&tmp);
		tmp = path[i];
		path[i] = ft_strjoin(path[i], f);
		ft_free(&tmp);
		if (stat(path[i], &g_buffer) == 0)
			return (ft_strdup(path[i]) + ft_free_star(path));
		i++;
	}
	return (NULL);
}

char	*path(char *f)
{
	char *s;
	char *tmp;

	if (is_cmd(f) || (stat(f, &g_buffer) == 0))
		return (ft_strdup(f));
	s = var("PATH");
	if (s == NULL)
	{
		ft_printf("bash: %s: No such file or directory\n", f);
		g_status = 1;
		return (NULL);
	}
	if ((tmp = help_path(s, f)) && ft_free(&s))
		return (tmp);
	ft_printf("bash: %s: command not found\n", f);
	g_status = 1;
	return (NULL);
}
