/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:29:34 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/14 18:29:35 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// int main(int argc,char **argv)
// {
//     if (argc == 1)
//     {
//         printf("must return to home\n");
//     }
//     else
//     {
//         if (chdir(argv[1]) != 0)
//             perror("error\n");
//     }
    
//     return 0;
// }




int main(int argc, char *argv[])
{
    char buffer[1000];
    char *h = getcwd(buffer,100);
    if (h != NULL)
        printf("%s\n",buffer);
    chdir(argv[1]);
    h = getcwd(buffer,100);
    if (h != NULL)
        printf("%s\n",buffer);
    
    return 0;
}

