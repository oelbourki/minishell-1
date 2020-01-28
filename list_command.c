/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commt_command_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:10:06 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/21 20:47:30 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_command	*ft_lstnew_command(char *str, int what)
{
	t_command	*new;

	new = (t_command*)malloc(sizeof(t_command));
	if (new == NULL)
		return (NULL);
	new->str = ft_strdup(str);
	new->what = what;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_command(t_command **alst, t_command *new)
{
	t_command	*tmp;

	tmp = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_lstclear_command(t_command **alst)
{
	t_command	*curr;
	t_command	*next;

	curr = *alst;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr->str);
		free(curr);
		curr = next;
	}
	*alst = NULL;
}
