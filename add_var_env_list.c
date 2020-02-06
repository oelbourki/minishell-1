/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var_env_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:49:34 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/27 18:18:18 by oel-bour         ###   ########.fr       */
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

t_env  *copyEnvp(char **envp)
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

/* you must remove that after finich */
