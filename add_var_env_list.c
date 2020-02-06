/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var_env_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:49:34 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/06 12:37:14 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back_envp(t_env **alst, t_env *new)
{
	t_env	*tmp;

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

t_env  *copyenvp(char **envp)
{
	int         i;
	t_env  	*node;
	t_env  	*lst = NULL;
	char		**splited;

	i = 0;
	while (envp[i] != NULL)
	{
		node = (t_env*)malloc(sizeof(t_env));
		splited = ft_split(envp[i], '=');
		node->variable = ft_strdup(splited[0]);
		node->value = ft_strdup(splited[1]);
		node->next = NULL;
		ft_lstadd_back_envp(&lst, node);
		free(splited[0]);
		free(splited[1]);
		free(splited);
		i++;
	}
	return (lst);
}

void	ft_lstclear_env(t_env **alst)
{
	t_env	*curr;
	t_env	*next;

	curr = *alst;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr->variable);
		free(curr->value);
		free(curr);
		curr = next;
	}
	*alst = NULL;
}

