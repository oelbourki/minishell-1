/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dollar_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:35:38 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/07 18:34:55 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	set_g_variables(char *new_str, char *var, int *j)
{
	int		k;

	while (g_variables != NULL)
	{
		if (ft_strncmp(var, g_variables->variable, ft_strlen(var)) == 0)
		{
			k = 0;
			while (g_variables->value[k] != '\0')
				new_str[(*j)++] = g_variables->value[k++];
			new_str[*j] = '\0';
			return ;
		}
		g_variables = g_variables->next;
	}
}

char	*set_command_return(char *new_str)
{
	int		k;
	char	*ret_string;

	k = 0;
	ret_string = ft_itoa(g_status);
	ft_strcpy(new_str, ret_string);
	return (new_str);
}

void	set_g_environt(char *new_str, char *var)
{
	int		k;
	int		j;

	j = 0;
	while (g_environt != NULL)
	{
		if (ft_strncmp(var, g_environt->variable, ft_strlen(var)) == 0)
		{
			k = 0;
			while (g_environt->value[k] != '\0')
				new_str[j++] = g_environt->value[k++];
			new_str[j] = '\0';
			return ;
		}
		g_environt = g_environt->next;
	}
	set_g_variables(new_str, var, &j);
	new_str[j] = '\0';
}

char	*put_value_of_dollar(char *str, int *i)
{
	char	var[256];
	char	*new_str;
	int		p;

	p = 0;
	if ((new_str = malloc(4096)) == NULL)
		return (NULL);
	new_str[0] = '\0';
	*i += 1;
	while (ft_isalnum(str[*i]) == 1 || str[*i] == '_' || str[*i] == '?')
		var[p++] = str[(*i)++];
	var[p] = '\0';
	if (strcmp(var, "?") == 0)
	{
		*i -= 1;
		return (set_command_return(new_str));
	}
	*i -= 1;
	set_g_environt(new_str, var);
	return (new_str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
