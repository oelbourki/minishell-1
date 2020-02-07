/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:48:15 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/07 18:34:55 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		to_lower(t_command **counter)
{
	t_command	*hold;
	int			l;
	int			i;
	char		*h;

	i = 0;
	hold = *counter;
	if (hold != NULL && hold->what == COMMAND)
	{
		l = ft_strlen(hold->str);
		h = (char*)malloc(l + 1);
		while (i < l)
		{
			h[i] = ft_tolower(hold->str[i]);
			i++;
		}
		h[i] = '\0';
		ft_free(&hold->str);
		hold->str = h;
	}
	return (1);
}

int		error_parse(t_command *counter)
{
	if (counter->what == REDIN)
		return (ft_print("bash: syntax error near unexpected token `<'\n"));
	else if (counter->what == DOUBLEREDOUT)
		return (ft_print("bash: syntax error near unexpected token `>>'\n"));
	else if (counter->what == REDOUT)
		return (ft_print("bash: syntax error near unexpected token `>'\n"));
	return (-1);
}

void	free_all(void)
{
	if (g_tmp != NULL)
		free(g_tmp);
	if (g_line != NULL)
		free(g_line);
	ft_lstclear_command(&g_command);
	ft_lstclear_env(&g_environt);
	ft_lstclear_env(&g_variables);
}
