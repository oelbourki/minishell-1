/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:26:46 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/07 11:48:13 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*parse_error(t_command *cmd)
{
	t_command	*tmp;
	t_command	*prev;

	tmp = cmd;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->what == STRING && tmp->next->what ==
		STRING && ft_strchr("|;<>", tmp->next->str[0]) != NULL)
		{
			tmp->str = ft_strjoin(tmp->str, tmp->next->str);
			tmp->next->str[0] = '\0';
			prev = tmp->next;
			tmp->next = tmp->next->next;
			free(prev->str);
			free(prev);
		}
		tmp = tmp->next;
	}
	return (cmd);
}
