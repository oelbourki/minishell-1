/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:29:28 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/14 18:29:29 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     main(int argc,char **argv)
{
	int i = -1;
	while (environ[++i] != NULL)
		;
    if (argv[1] != NULL)
	    environ[i] = strdup(argv[1]);	
	return 0;
}