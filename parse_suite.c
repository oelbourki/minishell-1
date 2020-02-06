/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_suite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:18:31 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/24 11:25:04 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	search_for_env_var(char *new, int *j, t_env *environt, char *var)
{
	int		i;

	i = 0;
	while (environt != NULL)
	{
		if (ft_strncmp(var, environt->variable, ft_strlen(var)) == 0)
		{
			while (environt->value[i] != '\0')
				new[(*j)++] = environt->value[i++];
			return ;
		}
		environt = environt->next;
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

char	*put_value_of_dollar(char *str, t_env *environt, int *i)
{
	char	var[256];
	char	*new_str = malloc(4096);
	int		k;
	int		j;
	int		p;

	p = 0;
	j = 0;
	new_str[0] = '\0';
	*i += 1;
	while (ft_isalnum(str[*i]) == 1 || str[*i] == '_')
		var[p++] = str[(*i)++];
	var[p] = '\0';
	while (environt != NULL)
	{
		if (ft_strncmp(var, environt->variable, ft_strlen(var)) == 0)
		{
			k = 0;
			while (environt->value[k] != '\0')
				new_str[j++] = environt->value[k++];
			break ;
		}
		environt = environt->next;
	}
	*i -= 1;
	new_str[j] = '\0';
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

t_command	*double_simple_qoute(t_command *cmd, t_env *environt)
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
			if (tmp->str[i] == '\\' && tmp->str[i + 1] != '\0')
				new[j++] = tmp->str[++i];
			else if (tmp->str[i] == '\'')
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
						new = ft_strcat(new, put_value_of_dollar(tmp->str, environt, &i), &j);
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
				// printf("newgogo = |%s|\n", new);
				new = ft_strcat(new, put_value_of_dollar(tmp->str, environt, &i), &j);
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
	return (cmd);
}
