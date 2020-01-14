/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:28:59 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/14 18:29:00 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"




int     main()
{
    pid_t pid[10],wpid;
    int status = 0;
    int fd[2];
    pipe(fd);
    char buffer[15];
    dup2(1,fd[1]);
    dup2(0,fd[0]);
    write(1,"bissmiallah\n",13);
    close(fd[0]);
    int i = 0;
    while (i < 10)
    {
        pid[i] = fork();
        if (pid < 0)
            perror(NULL);
        else if (pid[i] == 0)
        {
            close(fd[1]);
            read(fd[0],buffer,13);
            printf("%s\n",buffer);
        }
        i++;
    }
    while ((wpid = wait(&status)) > 0);
    return 0;
}