/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HOPE.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:51:56 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/26 13:45:27 by ibaali           ###   ########.fr       */
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
extern char **environ;

void	sig()
{
	printf("%d",WEXITSTATUS(status));
}


char **convert(t_command *head)
{
	redin = 0;
	char **argv = (char**)malloc(sizeof(char*) * 256);
	t_command *counter;
	counter = head;
	int i = 0;
	while (counter)
	{
		if (counter->what == PIPE || counter->what == SEMICOL)
			break;
		if (counter->what == DOUBLEREDOUT)
		{
			if (counter->next == NULL)
			{
				printf("bash: syntax error near unexpected token \\`newline\'\n");
				exit(-1);
			}
			file_output = strdup(counter->next->str);
			red_in = 1;
			break;
		}
		if (counter->what == REDOUT)
		{
			if (counter->next== NULL)
			{
				printf("bash: syntax error near unexpected token \\`newline\'\n");
				exit(-1);
			}
			file_output = strdup(counter->next->str);
			redout = 1;
			break;
		}
		if (counter->what == REDIN)
		{
			if (counter->next == NULL)
			{
				printf("bash: syntax error near unexpected token \\`newline\'\n");
				exit(-1);
			}
			file_input = strdup(counter->next->str);
			redin = 1;
			if (counter->next->next != NULL)
			{
				if (counter->next->next->what == REDOUT)
				{
					if (counter->next->next->next == NULL)
					{
						printf("bash: syntax error near unexpected token \\`newline\'\n");
						exit(-1);
					}
					else if (counter->next->next->next->what == REDIN || counter->next->next->next->what == REDOUT)
					{
						printf("bash: syntax error near unexpected token `%s'",counter->next->next->next->str);
						exit(-1);
					}
					file_output = strdup(counter->next->next->next->str);
					redout = 1;
				}
			}
			break;
		}
		if (counter->what == COMMAND)
			argv[i] = strdup(path(counter->str));
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
	int output_fd;
	int input_fd;

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
		redout = 0;
	}
	if (red_in == 1)
	{
		output_fd = open(file_output, O_APPEND | O_CREAT, 0777);
		dup2(output_fd, 1);
		red_in = 0;
	}
	if (redin == 1)
	{
		input_fd = open(file_input, O_RDONLY, 0);
		dup2(input_fd, 0);
		redin= 0;
	}
}
int   ft_exx(char **arg,int first,int last,int input)
{
	int status;
	int fd[2];
	pipe(fd);
	if (arg[0] == NULL)
		return -1;
	if (is_cmd(arg[0]) && p == 0 && redout == 0)
	{
		if (!strcmp(arg[0], "echo"))
			return echo(arg);
		if (!strcmp(arg[0], "pwd"))
			return pwd(1);
		if (!strcmp(arg[0], "cd"))
			return cd(arg[1]);
		if (!strcmp(arg[0], "env"))
			return env(environt);
		if (!strcmp(arg[0], "exit"))
			exit(0);
		// if (!strcmp(arg[0],"export"))
		// 	return (export(environ))
	}
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return 1;
	}
	else if (pid == 0)
	{
		dupx(first,last,input,fd);
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
		else 
		{
		signal(SIGINT,sig);
		if (execve(arg[0],&arg[0],environ))
				perror("exceve");
		}
			return 1;	
	}
	else 
		waitpid(pid,&status,0);

	// if (WIFEXITED(status))
	//     printf("Exit status: %d\n",WEXITSTATUS(status));
	// else if (WIFSIGNALED(status))
	//    printf("exit\n");
	if (last == 1)
		close(fd[0]);
	if (input != 0)
		close(input);
	close(fd[1]);
	return fd[0];
}


char *path(char *f)
{
	char *s = "/Users/ibaali/.brew/bin:/Users/ibaali/goinfre/.local:/Users/ibaali/.brew/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/munki:/Users/ibaali/.brew/bin:/Users/ibaali/goinfre/.local";
	char **path = ft_split(s,':');
	struct stat buffer;
	if (is_cmd(f))
	    return f;
	if (stat(f,&buffer) == 0)
		return  f;
	int i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i],"/");
		path[i] = ft_strjoin(path[i],f);
		if (stat(path[i],&buffer) == 0)
			return  path[i];
		i++;
	}
	printf("bash: %s: command not found\n",f);
	exit(-1);
}


int     the_main(t_command *head)
{
	int n = 0;
	int m = 0;
	t_command **semi = get_semi(head,&m);
	int i = 0;
	int j = 0;
	int first;
	t_command **pipe = NULL;
	int input = 0;
	while (i < m)
	{
		if (semi[i] != NULL)
		{
		j = 0;
		first = 1;
		pipe = get_pipe(semi[i],&n);
		// if (pipe == NULL)
		// 	return -1;
		while (j < n - 1)
		{
			p = 1;
			input = ft_exx(convert(pipe[j]),first,0,input);
			first = 0;
			j++;
		}
		char **arg = convert(pipe[j]);
		ft_exx(arg,first,1,input);
		p = 0;
		}
		i++;
	}
	return 0;
}

void    print_head(t_command *head)
{
	while (head)
	{
		printf("%s\n",head->str);
		head = head->next;
	}
}


// int main()
// {

// 	// print_arg(path);
// 	t_command *head;
// 	t_cmd *cmd = NULL;
// 	head = NULL;
// 	int fd;
// 	struct stat buffer;
// 	signal(SIGINT,sig);
// 	// push_back1(&head,"ls",COMMAND);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"cat",COMMAND);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"/usr/bin/wc",COMMAND);
// 	// push_back1(&head,">",REDOUT);
// 	// push_back1(&head,"123456789",STRING);

// 	// push_back1(&head,"cat",COMMAND);
// 	// push_back1(&head,"<",REDOUT);
// 	// push_back1(&head,"main.c",STRING);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"grep",COMMAND);
// 	// push_back1(&head,"main",STRING);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"otamn",STRING);
// 	// push_back1(&head,">",REDIN);
// 	// push_back1(&head,"101010",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"99999999",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"1111111",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"2222222",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"find",COMMAND);
// 	// push_back1(&head,".",STRING);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"xargs",COMMAND);
// 	// push_back1(&head,"basename",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"99999999",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"11111111",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"222222",STRING);
// 	// print_head(head);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"pwd",COMMAND);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"pwd",COMMAND);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"cd",COMMAND);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"pwd",COMMAND);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"cat",COMMAND);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"wc",COMMAND);
// 	// push_back1(&head,"-e",STRING);
// 	// push_back1(&head,"cd",COMMAND);
// 	// push_back1(&head,"123456777777",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"pwd",COMMAND);
// 	// push_back1(&head,"export",COMMAND);
// 	// push_back1(&head,"a=5",STRING);
// 	///////////
// 	// push_back1(&head,"cat",COMMAND);
// 	// push_back1(&head,"<",REDIN);
// 	// push_back1(&head,"libft.h",STRING);
// 		// push_back1(&head,"wc",COMMAND);
// 		// push_back1(&head,"-l",STRING);
// 		// push_back1(&head,"functions.c",STRING);
// 	push_back1(&head,"bc",COMMAND);
// 	// 	push_back1(&head,"<",REDIN);
// 	// push_back1(&head,"222222",STRING);
	
// 	the_main(head);
// 	// waitpid(pid,0,0);
// 	return 0;
// }