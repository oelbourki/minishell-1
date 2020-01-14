/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:29:17 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/14 18:29:18 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
int tab[10];

int     main()
{
    pid_t id;

    id = fork();
    if (id == 0)
    {
        puts("i am in child");
        i += 5;
    }
    wait(NULL);
    i++;
    printf("%d\n",i);
}