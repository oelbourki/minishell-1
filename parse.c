/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:13:42 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/22 15:47:19 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*putSpacecmd(int *start, int *fin, int *is_cmd, char *tmp, t_command *cmd)
{
	t_command	*node;

	while (tmp[*start] == ' ' || tmp[*start] == '\t')
		(*start) += 1;
	if (ft_strchr("|;<>", tmp[*start]) == NULL)
	{
		if (*is_cmd == 0)
			node = ft_lstnew_command(ft_substr(tmp, *start, *fin - *start), COMMAND);
		else
			node = ft_lstnew_command(ft_substr(tmp, *start, *fin - *start), STRING);
		ft_lstadd_back_command(&cmd, node);
	}
	*start = *fin;
	while (tmp[*fin] == ' ' || tmp[*fin] == '\t')
		(*fin) += 1;
	*is_cmd = 1;
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
		node = ft_lstnew_command(t, PIPE);
	else if (tmp[*i] == '<')
	{
		node = ft_lstnew_command(t, REDIN);
		*is_cmd = 1;
	}
	else
		node = ft_lstnew_command(t, SEMICOL);
	ft_lstadd_back_command(&cmd, node);
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
		node = ft_lstnew_command(t, DOUBLEREDOUT);
	}
	else
		node = ft_lstnew_command(t, REDOUT);
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
		if (tmp[i] == ' ')
			cmd = putSpacecmd(&start, &i, &is_cmd, tmp, cmd);
		if (tmp[i] == '\'' || tmp[i] == '\"')
			qoute = (qoute == 1) ? 0 : 1;
		if ((tmp[i] == '|' || tmp[i] == '<' || tmp[i] == ';') && qoute == 0)
			cmd = pipe_rin_semicol(&start, &i, &is_cmd, tmp, cmd);
		else if (tmp[i] == '>' && qoute == 0)
			cmd = rediriction_out(&start, &i, &is_cmd, tmp, cmd);
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
		printf("\nnode = $%s$ index = ", command->str);
		if (command->what == DOUBLEREDOUT)
			printf("DOUBLEREDOUT");
		else if (command->what == REDIN)
			printf("REDIN");
		else if (command->what == REDOUT)
			printf("REDOUT");
		else if (command->what == SEMICOL)
			printf("SEMICOL");
		else if (command->what == COMMAND)
			printf("COMMAND");
		else if (command->what == STRING)
			printf("STRING");
		else if (command->what == PIPE)
			printf("PIPE");
		command = command->next;
	}
	printf("\n");
}
