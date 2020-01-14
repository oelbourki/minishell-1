/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:28:43 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/14 18:28:44 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void    print(char **argv, int i,int argc)
{
    while (argv[i])
    {
        write(1,argv[i],strlen(argv[i]));
        if (i != argc - 1)
            write(1," ",1);
        i++;
    }
}
int main(int argc, char **argv)
{
    if (argc == 1)
        write(1,"\n",1);
    else if (argc > 2 && strcmp(argv[1],"-n") == 0)
        print(argv,2,argc);
    else
    {
        print(argv,1,argc);
        write(1,"\n",1);
    }
    return (0);
}