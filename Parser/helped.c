/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helped.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:32:46 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/06 16:32:55 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strcat(char *dest, char *src, int *j)
{
	int		i;
	int		k;
	char	*new;

	i = 0;
	k = 0;
	if ((new = malloc(4096)) == NULL)
		return (NULL);
	while (k < *j)
	{
		new[k] = dest[k];
		k++;
	}
	while (src[i] != '\0')
		new[(*j)++] = src[i++];
	return (new);
}
