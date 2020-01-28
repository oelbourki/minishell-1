/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HOPE.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:51:56 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/28 08:56:19 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int echo(char **argv);
char *file_input;
char *file_output;
int redin;
int redout;
int red_in;
int pid;
int status;
int p;
char *path(char *f);
int cd1(char *s);
	int output_fd;
	int input_fd;
extern char **environ;

void	sig()
{
	printf("%d",WEXITSTATUS(status));
}


int	doubleredout2(t_command *counter)
{
	if (counter->what == DOUBLEREDOUT)
	{
		if (counter->next == NULL)
		{
			printf("bash: syntax error near unexpected token \\`newline\'\n");
			return (1);
		}
		file_output = strdup(counter->next->str);
		red_in = 1;
		return (1);
	}
	return (0);
}

int		doubleredout(t_command *counter)
{
	if (counter->what == REDOUT)
	{
		if (counter->next == NULL)
		{
			printf("bash: syntax error near unexpected token \\`newline\'\n");
			return (1);
		}
		file_output = strdup(counter->next->str);
		redout = 1;
		return (1);
	}
	return (0);
}

int	helpredin(t_command *counter)
{
	if (counter->next->next->next == NULL)
	{
		printf("bash: syntax error near unexpected token \\`newline\'\n");
		return (1);
	}
	else if (counter->next->next->next->what == REDIN
	|| counter->next->next->next->what == REDOUT)
	{
		printf("bash: syntax error near unexpected token `%s'",counter->next->next->next->str);
		return (1);
	}
	return (0);
}
int		doubleredin(t_command *counter)
{
	if (counter->what == REDIN)
	{
		if (counter->next == NULL)
		{
			printf("bash: syntax error near unexpected token `newline\'\n");
			return (1);
		}
		file_input = strdup(counter->next->str);
		redin = 1;
		if (counter->next->next != NULL)
		{
			if (counter->next->next->what == REDOUT)
			{
				if (helpredin(counter))
					return (1);
				file_output = strdup(counter->next->next->next->str);
				redout = 1;
			}
			else if (counter->next->next->what == DOUBLEREDOUT)
			{
				if (helpredin(counter))
					return (1);
				file_output = strdup(counter->next->next->next->str);
				red_in = 1;
			}
		}
		return (1);
	}
	return (0);
}

char **convert(t_command *head)
{
	redin = 0;
	char **argv = (char**)malloc(sizeof(char*) * 256);
	t_command *counter;
	char *tmp;
	counter = head;
	int i = 0;
	while (counter)
	{
		if (counter->what == PIPE || counter->what == SEMICOL)
			break ;
		if (doubleredout2(counter))
			break ;
		if (doubleredout(counter))
			break ;
		if (doubleredin(counter))
			break ;
		if (counter->what == COMMAND)
		{
			if (counter->str != NULL && counter->str[0] != '=' && strrchr(counter->str, '='))
			{
				t_env *node = (t_env*)malloc(sizeof(t_env));
				char **arg = ft_split(counter->str,'=');
				node->variable = strdup(arg[0]);
				node->value = strdup(arg[1]);
				node->next = NULL;
				push_back_ex(&variables, node,arg);
				// ft_lstadd_back_envp(&variables, node);
				ft_free_star(arg);
				return (NULL);
			}
			else if (counter->str[0] == '=')
				printf("bash: %s: command not found",counter->str);
			tmp = path(counter->str);
			if (tmp == NULL)
			{
				ft_free(argv);
				return (NULL);
			}
			argv[i] = strdup(tmp);
		}
		else
			argv[i] = strdup(counter->str);
		counter = counter->next;
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

void	print_arg(char **argv)
{
	int i;

	i = 0;
	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}
}

int		end(int last, int input, int fd[2])
{
	if (last == 1)
		close(fd[0]);
	if (input != 0)
		close(input);
	close(fd[1]);
	return (fd[0]);
}

void	dupx(int first, int last, int input, int fd[2])
{
	if (first == 1 && last == 0 && input == 0)
		dup2(fd[1], 1);
	else if (first == 0 && last == 0 && input != 0)
	{
		dup2(input,0);
		dup2(fd[1], 1);
	}
	else
		dup2(input,0);
	if (redout == 1)
	{
		output_fd = open(file_output, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(output_fd, 1);
	}
	if (red_in == 1)
	{
		output_fd = open(file_output, O_RDWR | (O_APPEND |O_CREAT) , S_IRWXU);
		dup2(output_fd, 1);
	}
	if (redin == 1)
	{
		input_fd = open(file_input, O_RDONLY, 0);
		dup2(input_fd, 0);
	}
}
int   ft_exx(char **arg,int first,int last,int input)
{
	int status;
	int fd[2];

	if (arg == NULL)
		return (-1);
	pipe(fd);
	if (arg[0] == NULL)
		return (-1);
	if (is_cmd(arg[0]) && p == 0 && redout == 0 && redin == 0 && red_in == 0)
	{
		if (!strcmp(arg[0], "echo"))
			return (echo(arg));
		if (!strcmp(arg[0], "pwd"))
			return (pwd(1));
		if (!strcmp(arg[0], "cd"))
			return (cd(arg[1]));
		if (!strcmp(arg[0], "env"))
			return (env(environt));
		if (!strcmp(arg[0], "exit"))
			exit(0);
		if (!strcmp(arg[0], "export"))
			return (export(arg));
		if (!strcmp(arg[0], "unset"))
			return (unset(arg));
		if (!strcmp(arg[0], "var"))
			return (env_var(variables));
	}
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		dupx(first, last, input, fd);
		if (!strcmp(arg[0], "cd"))
		{
			cd(arg[1]);
			exit(0);
		}
		else if (!strcmp(arg[0], "pwd"))
		{
			pwd(1);
			exit(0);
		}
		else if (!strcmp(arg[0], "echo"))
		{
			echo(arg);
			exit(0);
		}
		else if (!strcmp(arg[0], "env"))
		{
			env(environt);
			exit(0);
		}
		else if (!strcmp(arg[0], "unset"))
		{
			unset(arg);
			exit(0);
		}
		else if (!strcmp(arg[0], "export"))
		{
			export(arg);
			exit(0);
		}
		else
		{
			if (execve(arg[0], &arg[0], environ))
					perror("exceve");
		}
		if (redout == 1)
		{
			close(output_fd);
			redout = 0;
		}
		if (red_in == 1)
		{
			close(output_fd);
			red_in = 0;
		}
		if (redin == 1)
		{
			close(input_fd);
			redin = 0;
		}
			return (1);
		}
	else 
		waitpid(pid,&status,0);
	// if (WIFEXITED(status))
	//     printf("Exit status: %d\n",WEXITSTATUS(status));
	// else if (WIFSIGNALED(status))
	//    printf("exit\n");
	red_in = 0;
	redin = 0;
	redout = 0;
	return (end(last, input, fd));
}


char *path(char *f)
{
	int i;
	char *s = var("PATH");
	char **path;
	struct stat buffer;
	char *tmp;

	i = 0;
	path = ft_split(s, ':');
	if (is_cmd(f))
		return (f);
	if (stat(f, &buffer) == 0)
		return (f);
	while (path[i])
	{
		tmp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		ft_free(&tmp);
		tmp = path[i];
		path[i] = ft_strjoin(path[i], f);
		ft_free(&tmp);
		if (stat(path[i], &buffer) == 0)
			return (path[i]);
		i++;
	}
	puts("<<<<<>>>>>>");
	printf("bash: %s: command not found",f);
	return (NULL);
}


int     the_main(t_command *head)
{
	int n = 0;
	int m = 0;
	t_command **semi;
	int i = 0;
	int j = 0;
	int first;
	t_command **pipe = NULL;
	int input = 0;
	char **arg;
	semi = get_semi(head, &m);
	while (i < m)
	{
		if (semi[i] != NULL)
		{
			j = 0;
			first = 1;
			pipe = get_pipe(semi[i], &n);
			while (j < n - 1)
			{
				p = 1;
				arg = convert(pipe[j]);
				input = ft_exx(arg, first, 0, input);
				ft_free_star(arg);
				first = 0;
				j++;
			}
			arg = convert(pipe[j]);
			ft_exx(arg, first, 1, input);
			ft_free_star(arg);
			p = 0;
		}
		i++;
	}
	return (0);
}

void    print_head(t_command *head)
{
	while (head)
	{
		printf("%s\n",head->str);
		head = head->next;
	}
}
