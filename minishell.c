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


// void space_split(char *ag,t_cmd *list)
// {
// 	// char **sp = ft_split(ag,' ');
// 	printf("before = $%s$\n", list->ag[0]);
// 	list->ag = ft_split(ag,' ');
// 	printf("after = $%s$\n", list->ag[0]);
// 	int i = 0;
// 	while (list->ag[i])
// 	{
// 		if (!strcmp(list->ag[i], ">") || !strcmp(list->ag[i], ">>") || !strcmp(list->ag[i], "<"))
// 		{
// 			if (!strcmp(list->ag[i], ">"))
// 			{
// 				list->red_create_output = 1;
// 				strcpy(list->file_output, list->ag[i+ 1]);
// 			}
// 			else if (!strcmp(list->ag[i], ">>"))
// 			{
// 				list->red_append_output = 1;
// 				strcpy(list->file_output, list->ag[i+ 1]);
// 			}
// 			else if (!strcmp(list->ag[i], "<"))
// 			{
// 				list->red_input = 1;
// 				strcpy(list->file_input, list->ag[i+ 1]);
// 			}
// 			free(list->ag[i]);
// 			list->ag[i] = NULL;
// 		}
// 		i++;
// 	}
// 	// list->ag = sp;
// }

void 	pipe_split(char *ag,t_cmd *list)
{
	char **sp = ft_split(ag,'|');
	int i = 0;
	while (sp[i])
	{
		//space_split(sp[i], list);

		i++;
	}
}
int		main(void)
{
	char	*command;
	char	*tmp;
	int		i;
	int		P_id;
	t_cmd	*list[256] = {0};

	while (1)
	{
		ft_putstr_fd("root@e2r10p5:~# ", 1);
		get_next_line(1, &command);
		tmp = command;
		command = ft_strtrim(command, " \t");
		free(tmp);
		char **ag = ft_split(command, ';');
		i = 0;
		while (ag[i] != NULL)
		{
			list[i]->ag[0] = strdup("wale");
			pipe_split(ag[i], list[i]);
			printf("command = $%s$\n", list[i]->ag[0]);
			i++;
		}
		free(command);
	}
	return (0);
}
