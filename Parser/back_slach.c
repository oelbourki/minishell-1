/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_slach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:39:27 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/06 14:16:58 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

char	*back_slach(char *new, char *str, int *i, int *j)
{
	g_slach = 0;
	g_put = 0;
	while (str[*i] != '\0')
	{
		if (str[*i] == '\\')
			putbachslach(str, new, i, j);
		else if (str[*i] == '$' && (g_slach % 2) == 0)
		{
			*i -= 1;
			new[*j] = '\0';
			return (new);
		}
		else
			new[(*j)++] = str[(*i)];
		if (str[*i] == '\0')
			break ;
		*i += 1;
	}
	new[*j] = '\0';
	return (new);
}
