/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_ex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:06:50 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/04 15:30:30 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command **get_semi(t_command *head, int *n)
{
    t_command *counter;
    t_command **tab;
    int i;

    if (head == NULL)
        return (NULL);
    counter = head;
    tab = (t_command**)calloc(10, sizeof(t_command*));
    i = 1;
    if (head->what != SEMICOL)
        tab[0] = head;
    while (counter)
    {
        if (counter->what == SEMICOL)
        {
            tab[i] = counter->next;
            i++;
        }
        counter = counter->next;
    }
    *n = i;
    return tab;
}

t_command **get_pipe(t_command *head,int *n)
{
    t_command **tab;
    int i;

    if (head == NULL)
        return NULL;
    tab = NULL;
    tab = (t_command**)calloc(10, sizeof(t_command*));
    i = 1;
    tab[0] = head;
    while (head != NULL)
    {
        if (head->what == SEMICOL)
            break;
        if (head->what == PIPE)
        {
            tab[i] = head->next;
            i++;
        }
        head = head->next;
    }
    *n = i;
    return tab;
}