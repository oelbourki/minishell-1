/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:52:00 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/04 21:56:04 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int help_push(t_env **head,t_env *data,char **s)
{
    t_env *counter;

    counter = *head;
    if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0)
    {
        ft_free(&counter->value);
        counter->value = ft_strdup(s[1]);
        return (1);
    }
    return (0);
}

void    push_back_ex(t_env **head,t_env *data,char **s)
{
    t_env *counter = *head;

    if (counter == NULL)
    {
        *head = data;
        return ;
    }
    if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0)
    {
        ft_free(&counter->value);
        counter->value = ft_strdup(s[1]);
        return ;
    }
    while (counter->next)
    {
        if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0 &&
        ft_free(&counter->value))
        {
            counter->value = ft_strdup(s[1]);
            return ;
        }
        counter = counter->next;
    }
    if (!help_push(&counter, data, s))
        counter->next = data;
}

//-------
t_command   *creat_(char *str,int what)
{
    t_command *tmp = (t_command*)malloc(sizeof(t_command));
    if (tmp == NULL)
        return NULL;
    tmp->str = ft_strdup(str);
    tmp->what = what;
    tmp->next = NULL;
    return tmp;
}

void    push_back1(t_command **head,char *str,int what)
{
    t_command *data = creat_(str,what);

    if (*head == NULL)
    {
        *head = data;
        return;
    }
    else 
    {
        t_command *counter = *head;
        while (counter->next)
        {
            counter = counter->next;
        }
        counter->next = data;
    }

}

//------