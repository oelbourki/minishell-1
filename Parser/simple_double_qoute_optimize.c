/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_double_qoute_optimize.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:18:31 by ibaali            #+#    #+#             */
/*   Updated: 2020/02/06 22:17:31 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		finition_simple_qoute(int *i, t_command *tmp, char *new, int *j)
{
	(*i) += 1;
	while (tmp->str[*i] != '\'' && tmp->str[*i] != '\0')
		new[(*j)++] = tmp->str[(*i)++];
	if (tmp->str[(*i)] == '\0')
	{
		write(1, "Multi line detected..!!!", 24);
		exit(-1);
	}
}

void		finition_double_qoute(int *i, t_command *tmp, char **new, int *j)
{
	(*i) += 1;
	while (tmp->str[*i] != '"' && tmp->str[*i] != '\0')
	{
		if (tmp->str[*i] == '\\' && ft_strchr("\\\"$", tmp->str[(*i) + 1]))
			(*new)[(*j)++] = tmp->str[++(*i)];
		else if (tmp->str[*i] == '$')
			*new = ft_strcat(*new, put_value_of_dollar(tmp->str,
			g_environt, i), j);
		else
			(*new)[(*j)++] = tmp->str[*i];
		(*i) += 1;
	}
	if (tmp->str[*i] == '\0')
	{
		write(1, "Multi line detected..!!!\n", 25);
		exit(-1);
	}
}

int			norm_double_simple_qoute(int *i, int *j, t_command *tmp, char **new)
{
	if (tmp->str[*i] == '\'')
		finition_simple_qoute(i, tmp, *new, j);
	else if (tmp->str[*i] == '"')
		finition_double_qoute(i, tmp, new, j);
	else if (tmp->str[*i] == '$')
	{
		(*new)[*j] = '\0';
		*new = ft_strcat(*new, put_value_of_dollar(tmp->str,
		g_environt, i), j);
	}
	else if (tmp->str[*i] == '\\')
	{
		*new = back_slach(*new, tmp->str, i, j);
		if (tmp->str[*i] == '\0')
			return (-1);
	}
	else
		(*new)[(*j)++] = tmp->str[*i];
	return (0);
}

void		free_tmp_strdup(t_command *tmp, char *new)
{
	char	*a_free;

	a_free = tmp->str;
	tmp->str = ft_strdup(new);
	free(a_free);
}

t_command	*double_simple_qoute(t_command *cmd, t_env *g_environt)
{
	t_command	*tmp;
	int			i;
	int			j;
	char		*new;

	tmp = cmd;
	if ((new = malloc(4096)) == NULL)
		return (NULL);
	while (tmp != NULL)
	{
		i = 0;
		j = 0;
		while (tmp->str[i] != '\0')
		{
			if (norm_double_simple_qoute(&i, &j, tmp, &new) == -1)
				break ;
			i++;
		}
		new[j] = '\0';
		free_tmp_strdup(tmp, new);
		tmp = tmp->next;
	}
	free(new);
	return (cmd);
}
