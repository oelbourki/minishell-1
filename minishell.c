/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 22:27:39 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/14 09:24:35 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_strcut(t_cmd *list)
{

}
void space_split(char *ag,t_cmd *list)
{
	list->argument = ft_split(ag,' ');
	int i = 0;
	while (list->argument[i])
	{
		if (!strcmp(list->argument[i], ">") || !strcmp(list->argument[i], ">>") || !strcmp(list->argument[i], "<"))
		{
			if (!strcmp(list->argument[i], ">"))
			{
				list->red_create_output = 1;
				strcpy(list->file_output, list->argument[i+ 1]);
			}
			else if (!strcmp(list->argument[i], ">>"))
			{
				list->red_append_output = 1;
				strcpy(list->file_output, list->argument[i+ 1]);
			}
			else if (!strcmp(list->argument[i], "<"))
			{
				list->red_input = 1;
				strcpy(list->file_input, list->argument[i+ 1]);
			}
			free(list->argument[i]);
			list->argument[i] = NULL;
		}
		i++;
	}
}

void 	pipe_split(char *ag,t_cmd *list)
{
	char **sp = ft_split(ag,'|');
	if (sp == NULL)
		perror(NULL);
	int i = 0;
	while (sp[i])
	{
		space_split(sp[i], list);
		i++;
	}
}
int		main(void)
{
	char	*command;
	char	*tmp;
	int		i;
	int		P_id;
	t_cmd	*list[256];
	// list = (t_cmd**)malloc(sizeof(t_cmd*) * );

	while (1)
	{
		ft_putstr_fd("root@e2r10p5:~# ", 1);
		get_next_line(1, &command);
		tmp = command;
		command = ft_strtrim(command, " \t");
		free(tmp);
		char **ag = ft_split(command, ';');
		if (ag == NULL)
			perror(NULL);
		i = 0;
		while (ag[i] != NULL)
		{
			list[i] = (t_cmd*)malloc(sizeof(t_cmd));
			pipe_split(ag[i], list[i]);
			// printf("command = $%s$\n", ag[i]);
			i++;
		}
		free(command);
	}
	return (0);
}
