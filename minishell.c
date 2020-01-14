/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 22:27:39 by ibaali            #+#    #+#             */
/*   Updated: 2020/01/14 10:29:45 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_strcut(t_cmd *list)
{
<<<<<<< HEAD
	int i = 0;
	while (list->argument[i])
	{
		printf("arg[%d]%s\n",i,list->argument[i]);
		i++;
	}
	printf("red_create_output[%d]\n",list->red_create_output);
	printf("red_append_output[%d]\n",list->red_append_output);
	printf("red_input[%d]\n",list->red_input);
	printf("file_input>>[%s]\n",list->file_input);
	printf("file_input>>[%s]\n",list->file_output);
=======
	int		i;

	i = 0;
	while (list->argument[i] != NULL)
	{
		printf("list->argument[%d] = $%s$\n", i, list->argument[i]);
		i += 1;
	}
	printf("is create rederiction = $%d$\n", list->red_create_output);
	printf("is append rederiction = $%d$\n", list->red_append_output);
	printf("is input rederiction = $%d$\n", list->red_input);
	printf("file input name = $%s$\n", list->file_input);
	printf("is output name = $%s$\n", list->file_output);
}

void	init_strcut(t_cmd *list)
{
	list->argument = NULL;	
	list->red_create_output = 0;
	list->red_append_output = 0;
	list->red_input = 0;
	list->file_input = NULL;
	list->file_output = NULL;
	list->next = NULL;
>>>>>>> master
}

void space_split(char *ag,t_cmd *list)
{
	list->argument = ft_split(ag,' ');
	int i = 0;
	while (list->argument[i])
	{
		if (list->argument[i] != NULL && (!strcmp(list->argument[i], ">") || !strcmp(list->argument[i], ">>") || !strcmp(list->argument[i], "<")))
		{
			if (!strcmp(list->argument[i], ">"))
			{
				list->red_create_output = 1;
				list->file_output = ft_strdup(list->argument[i+ 1]);
			}
			else if (!strcmp(list->argument[i], ">>"))
			{
				list->red_append_output = 1;
				list->file_output = ft_strdup(list->argument[i+ 1]);
			}
			else if (!strcmp(list->argument[i], "<"))
			{
				list->red_input = 1;
				list->file_input = ft_strdup(list->argument[i+ 1]);
			}
			free(list->argument[i]);
			list->argument[i] = NULL;
		}
		i++;
	}
	print_strcut(list);
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
			init_strcut(list[i]);
			pipe_split(ag[i], list[i]);
			print_strcut(list[i]);
			i++;
		}
		free(command);
	}
	return (0);
}
