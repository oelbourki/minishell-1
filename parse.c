/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:13:42 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/27 20:48:11 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int		g_to_skip;

t_command	*add_back_slach(int *start, int *i, t_command *cmd)
{
	t_command	*node;

	node = ft_lstnew_command("\\", STRING);
	ft_lstadd_back_command(&cmd, node);
	return (cmd);
}

t_command	*putSpacecmd(int *start, int *fin, int *is_cmd, char *tmp, t_command *cmd)
{
	t_command	*node;
	char		*a_free;

	a_free = ft_substr(tmp, *start, *fin - *start);
	if (ft_strchr(a_free, '\\'))
	{
		*start = (*fin);
		free(a_free);
		return (cmd);
	}
	while (tmp[*start] == ' ' || tmp[*start] == '\t')
		(*start) += 1;
	if (ft_strchr("|;<>", tmp[*start]) == NULL && *start < *fin)
	{
		if (*is_cmd == 0)
			node = ft_lstnew_command(a_free, COMMAND);
		else
			node = ft_lstnew_command(a_free, STRING);
		ft_lstadd_back_command(&cmd, node);
	}
	if (*start < *fin)
		*is_cmd = 1;
	*start = *fin;
	while (tmp[*fin] == ' ' || tmp[*fin] == '\t')
		(*fin) += 1;
	return (cmd);
}

t_command	*pipe_rin_semicol(int *start, int *i, int *is_cmd, char *tmp, t_command *cmd)
{
	t_command	*node;
	char		t[2];

	t[0] = tmp[*i];
	t[1] = '\0';
	cmd = putSpacecmd(start, i, is_cmd, tmp, cmd);
	*is_cmd = 0;
	if (tmp[*i] == '|')
		if (g_to_skip == 0)
			node = ft_lstnew_command(t, PIPE);
		else
			node = ft_lstnew_command(t, STRING);
	else if (tmp[*i] == '<')
	{
		if (g_to_skip == 0)
			node = ft_lstnew_command(t, REDIN);
		else
			node = ft_lstnew_command(t, STRING);
		*is_cmd = 1;
	}
	else
	{
		if (g_to_skip == 0)
			node = ft_lstnew_command(t, SEMICOL);
		else
			node = ft_lstnew_command(t, STRING);
	}
	ft_lstadd_back_command(&cmd, node);
	if (g_to_skip == 1)
		g_to_skip = 0;
	*start = *i + 1;
	return (cmd);
}

t_command	*rediriction_out(int *start, int *i, int *is_cmd, char *tmp, t_command *cmd)
{
	t_command	*node;
	char		t[3];

	t[0] = '>';
	t[1] = '\0';
	cmd = putSpacecmd(start, i, is_cmd, tmp, cmd);
	*start = *i + 1;
	if (tmp[*i + 1] == '>')
	{
		t[1] = '>';
		t[2] = '\0';
		*i += 1;
		*start = *i + 1;
		if (g_to_skip == 0)
			node = ft_lstnew_command(t, DOUBLEREDOUT);
		else
			node = ft_lstnew_command(t, REDOUT);
	}
	else
	{
		if (g_to_skip == 0)
			node = ft_lstnew_command(t, REDOUT);
		else
		{
			node = ft_lstnew_command(t, STRING);
			if (g_to_skip == 1)
				g_to_skip = 0;
		}
	}
	ft_lstadd_back_command(&cmd, node);
	return (cmd);
}

t_command	*parse(char *line, t_command *cmd)
{
	int		i;
	int		start;
	char	*tmp;
	int		is_cmd;
	int		qoute;

	i = 0;
	start = 0;
	is_cmd = 0;
	qoute = 0;
	tmp = ft_strtrim(line, " \t");
	while (tmp[i] != '\0')
	{
		if (ft_strchr(" \t", tmp[i]) != NULL && qoute == 0)
			cmd = putSpacecmd(&start, &i, &is_cmd, tmp, cmd);
		if (tmp[i] == '\'' || tmp[i] == '\"')
			qoute = (qoute == 1) ? 0 : 1;
		if ((tmp[i] == '|' || tmp[i] == '<' || tmp[i] == ';') && qoute == 0)
			cmd = pipe_rin_semicol(&start, &i, &is_cmd, tmp, cmd);
		else if (tmp[i] == '>' && qoute == 0)
			cmd = rediriction_out(&start, &i, &is_cmd, tmp, cmd);
		if (tmp[i] == '\\')
		{
			if (g_to_skip == 1)
				cmd = add_back_slach(&start, &i, cmd);
			g_to_skip = (g_to_skip == 0) ? 1 : 0;
			// i++;
		}
		i++;
	}
	cmd = putSpacecmd(&start, &i, &is_cmd, tmp, cmd);
	free(tmp);
	return (cmd);
}

/* you must remove that after finich */
void	print_command(t_command *command)
{
	while (command != NULL)
	{
		printf("\nnode = [%s] index = ", command->str);
		if (command->what == DOUBLEREDOUT)
			printf("DOUBLEREDOUT");
		else if (command->what == REDIN)
			printf("REDIN\n");
		else if (command->what == REDOUT)
			printf("REDOUT\n");
		else if (command->what == SEMICOL)
			printf("SEMICOL\n");
		else if (command->what == COMMAND)
			printf("COMMAND\n");
		else if (command->what == STRING)
			printf("STRING\n");
		else if (command->what == PIPE)
			printf("PIPE\n");
		command = command->next;
	}
	printf("\n");
}
