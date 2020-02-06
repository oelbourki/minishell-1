/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_suite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:18:31 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/06 12:32:01 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	search_for_env_var(char *new, int *j, t_env *g_environt, char *var)
{
	int		i;

	i = 0;
	while (g_environt != NULL)
	{
		if (ft_strncmp(var, g_environt->variable, ft_strlen(var)) == 0)
		{
			while (g_environt->value[i] != '\0')
				new[(*j)++] = g_environt->value[i++];
			return ;
		}
		g_environt = g_environt->next;
	}
}

int			where_is_char(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strcat(char *dest, char *src, int *j)
{
	int		i;
	int		k;
	char	*new = malloc(4096);

	i = 0;
	k = 0;
	while (k < *j)
	{
		new[k] = dest[k];
		k++;
	}
	while (src[i] != '\0')
		new[(*j)++] = src[i++];
	return (new);
}

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

char	*put_value_of_dollar(char *str, t_env *g_environt, int *i)
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

char	*backSlach(char *new, char *str, int *i, int *j)
{
	int		slach;
	int		put;

	slach = 0;
	put = 0;
	while (str[*i] != '\0')
	{
		if (str[*i] == '\\')
		{
			while (str[*i] == '\\')
			{
				if (put == 0)
					new[(*j)++] = str[(*i)++];
				else
					(*i) += 1;
				put = (put == 0) ? 1 : 0;
				slach += 1;
			}
			if (slach % 2 == 1)
				*j -= 1;
			*i -= 1;
		}
		else if (str[*i] == '$' && (slach % 2) == 0)
		{
			*i -= 1;
			new[*j] = '\0';
			return (new);
		}
		else
			new[(*j)++] = str[(*i)];
		if (str[*i] == '\0')
			break ;
		// if (str[*i] == '\0') old one
		// {
		// 	new[*j] = '\0';
		// 	return (new);
		// }
		*i += 1;
	}
	new[*j] = '\0';
	return (new);
}

t_command	*double_simple_qoute(t_command *cmd, t_env *g_environt)
{
	t_command	*tmp;
	int			i;
	int			j;
	int			flag;
	char		*new;

	tmp = cmd;
	flag = 0;
	if ((new = malloc(4096)) == NULL)
		return (NULL);
	while (tmp != NULL)
	{
		i = 0;
		j = 0;
		while (tmp->str[i] != '\0')
		{
			if (tmp->str[i] == '\'')
			{
				i += 1;
				while (tmp->str[i] != '\''  && tmp->str[i] != '\0')
					new[j++] = tmp->str[i++];
				if (tmp->str[i] == '\0')
				{
					write(1, "Multi line detected..!!!", 24);
					return (NULL);
				}
			}
			else if (tmp->str[i] == '"')
			{
				i += 1;
				while (tmp->str[i] != '"' && tmp->str[i] != '\0')
				{
					if (tmp->str[i] == '\\' && ft_strchr("\\\"$", tmp->str[i + 1]))
						new[j++] = tmp->str[++i];
					else if (tmp->str[i] == '$')
					{
						new = ft_strcat(new, put_value_of_dollar(tmp->str, g_environt, &i), &j);
					}
					else
						new[j++] = tmp->str[i];
					i += 1;
				}
				if (tmp->str[i] == '\0')
				{
					write(1, "Multi line detected..!!!", 24);
					return (NULL);
				}
			}
			else if (tmp->str[i] == '$')
			{
				new[j] = '\0';
				new = ft_strcat(new, put_value_of_dollar(tmp->str, g_environt, &i), &j);
			}
			else if (tmp->str[i] == '\\')
			{
				// printf("blakooooo\n");
				new = backSlach(new, tmp->str, &i, &j);
				if (tmp->str[i] == '\0')
					break ;
			}
			else
				new[j++] = tmp->str[i];
			i++;
		}
		new[j] = '\0';
		char *a_free;
		a_free = tmp->str;
		tmp->str = ft_strdup(new);
		free(a_free);
		tmp = tmp->next;
	}
	free(new);
	return (cmd);
}
