/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_slach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:39:27 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/12 14:42:12 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		g_slach;
int		g_put;

void	putbachslach(char *str, char *new, int *i, int *j)
{
	while (str[*i] == '\\')
	{
		if (g_put == 0)
			new[(*j)++] = str[(*i)++];
		else
			(*i) += 1;
		g_put = (g_put == 0) ? 1 : 0;
		g_slach += 1;
	}
	if (g_slach % 2 == 1)
		*j -= 1;
	*i -= 1;
}

int		skipped_double_simple_qoute(char *str, int *i, char *new, int *j)
{
	if (ft_strchr("\"'", str[(*i)]) != NULL && g_slach % 2 == 0)
	{
		(*i) -= 1;
		return (-1);
	}
	new[(*j)++] = str[(*i)];
	if ((new[(*j) - 1] == '"' && str[(*i) + 1] == '"') ||
	(new[(*j) - 1] == '\'' && str[(*i) + 1] == '\''))
		return (-1);
	return (0);
}

char	*back_slach(char *new, char *str, int *i, int *j)
{
	g_slach = 0;
	g_put = 0;
	while (str[*i] != '\0' && ft_strchr(" \t", str[*i]) == NULL)
	{
		if (str[*i] == '\\')
			putbachslach(str, new, i, j);
		else if (str[*i] == '$' && (g_slach % 2) == 0)
		{
			*i -= 1;
			new[*j] = '\0';
			return (new);
		}
		else if (skipped_double_simple_qoute(str, i, new, j) == -1)
			break ;
		if (str[*i] == '\0')
			break ;
		*i += 1;
	}
	new[*j] = '\0';
	return (new);
}
