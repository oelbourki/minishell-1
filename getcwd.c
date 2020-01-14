/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:29:55 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/14 18:29:56 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char *argv[])
{
    char buffer[256];
    char *h = getcwd(buffer,256);
    if (h != NULL)
        printf("%s\n",buffer);
    return 0;
}
