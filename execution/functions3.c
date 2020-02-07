/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:48:15 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/07 12:16:36 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void   to_lower(t_command **counter)
{
    t_command *hold;
    int l;
    int i;
    char *h;

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
}

int error_parse(t_command *counter)
{
    if (counter->what == REDIN)
        return (ft_print("bash: syntax error near unexpected token `<'\n"));
    else if (counter->what == DOUBLEREDOUT)
        return (ft_print("bash: syntax error near unexpected token `>>'\n"));
    else if (counter->what == REDOUT)
        return (ft_print("bash: syntax error near unexpected token `>'\n"));
    return (-1);
}