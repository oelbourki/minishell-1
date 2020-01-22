/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_suite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:18:31 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/22 16:23:58 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*remove_simple_qoute(char *str)
{
	char	*tmp;

	tmp = str;
	str = ft_strtrim(str, "'");
	free(tmp);
	return (str);
}

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

char	*remove_double_qoute(char *str, t_env *environt)
{
	char	*new_str = malloc(4096);
	char	var[256];
	int		k;
	int		i;
	int		j;

	i = 0;
	j = 0;
	k = 0;
	i += 1;
	while (str[i] != '\"')
	{
		if (str[i] == '$')
		{
			while (ft_isalnum(str[i + 1]) == 1 || str[i + 1] == '_')
				var[k++] = str[++i];
			var[k] = 0;
			search_for_env_var(new_str, &j, environt, var);
		}
		else
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

char		*put_value_of_dollar(char *str, t_env *environt)
{
	char	var[256];
	char	*new_str = malloc(4096);
	int		i;
	int		j;

	i = 1;
	j = 0;
	new_str[0] = '\0';
	while (ft_isalnum(str[i]) == 1 || str[i] == '_')
		var[j++] = str[i++];
	var[j] = '\0';
	j = 0;
	i = 0;
	while (environt != NULL)
	{
		if (ft_strncmp(var, environt->variable, ft_strlen(var)) == 0)
		{
			while (environt->value[i] != '\0')
				new_str[j++] = environt->value[i++];
			new_str[j] = '\0';
			return (new_str);
		}
		environt = environt->next;
	}
	return (new_str);
}

t_command	*double_simple_qoute(t_command *cmd, t_env *environt)
{
	t_command	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		if (tmp->str[0] == '\'' && tmp->what == STRING)
			tmp->str = remove_simple_qoute(tmp->str);
		else if (tmp->str[0] == '\"' && tmp->what == STRING)
			tmp->str = remove_double_qoute(tmp->str, environt);
		else if (tmp->str[0] == '$' && tmp->what == STRING)
			tmp->str = put_value_of_dollar(tmp->str, environt);
		tmp = tmp->next;
	}
	return (cmd);
}
