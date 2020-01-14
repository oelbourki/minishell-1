/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:28:51 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/14 18:28:52 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int argc,char **argv)
{
    char path[256];
    if (argc == 1)
    {
        printf("%s",getcwd(path,256));
        printf("\n");
    }else
    {
        printf("pwd: too many arguments");
    }
    
    return 0;
}