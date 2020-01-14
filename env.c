/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:29:11 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/14 18:29:12 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int     main(int argc,char **argv)
{
	int i = 0;
	puts(environ[0]);
	while (environ[i] != NULL)
	{	write(1,"ok\n",3);
		write(1,environ[i],strlen(environ[i]));
		i++;
	}
	return 0;
}