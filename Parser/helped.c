/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helped.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:32:46 by ibaali            #+#    #+#             */
/*   Updated: 2020/03/01 11:45:35 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strcat(char *dest, char *src, int *j)
{
	int		i;
	int		k;
	char	*new;

	i = 0;
	k = 0;
	if ((new = malloc(4096)) == NULL)
		return (NULL);
	while (k < *j)
	{
		new[k] = dest[k];
		k++;
	}
	while (src[i] != '\0')
		new[(*j)++] = src[i++];
	free(dest);
	free(src);
	return (new);
}

void	help_double_simple_qoute(t_command *tmp, char **new, int i, int j)
{
	if (ft_strcmp(tmp->str, "\\") == 0)
	{
		tmp->str[0] = ' ';
		tmp = tmp->next;
		return ;
	}
	while (tmp->str[i] != '\0')
	{
		if (norm_double_simple_qoute(&i, &j, tmp, new) == -1)
			break ;
		i++;
	}
	(*new)[j] = '\0';
	free_tmp_strdup(tmp, *new);
}
