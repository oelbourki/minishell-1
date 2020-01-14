#include "minishell.h"

int   echo(char **arg);

void    displayPrompt()
{
	write(1,"AGI>>",5);
}


// int   command(char **arg)
// {
// 	if (!strcmp(arg[0],commands[0]))
// 		echo(arg);
// 	else if (!strcmp(arg[0],commands[1]))
// 	return 0;
// }

int   ft_ex(char **arg,char **env)
{
	int pid;
	int status;
	int fd[2];
	pipe(fd);
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return 1;
	}
	else if (pid == 0)
	{
		if (execve(arg[0],&arg[0],env))
			perror("exceve");
		return 1;
	}
	else 
		wait(&status);
	return 0;
}
// int   pwd(char **arg)
// {
// 	int pid;
// 	int status;

// 	if ((pid = fork()) == -1)
// 	{
// 		perror("fork");
// 		return 1;
// 	}
// 	else if (pid == 0)
// 	{
// 		if (execve(arg[0],&arg[0],NULL))
// 			perror("exceve");
// 		return 1;
// 	}
// 	else 
// 		wait(&status);
// 	return 0;
// }
// int	putenv_(const char *string)
// {
// 	int i = -1;
// 	while (environ[++i] != NULL)
// 		;
// 	environ[i] = strdup(string);	
// 	return 0;
// }
// int	printenv()
// {
// 	int i = -1;
// 	while (environ[++i] != NULL)
// 		puts(environ[i]);
// 	return 0;
// }
char   **cmd_proce(char *buffer)
{  
	char **cmd = ft_split(buffer,' ');
	return cmd;
}
int main(int argc, char *argv[])
{
	char *buffer;
	char *line;
	char **env;
	int stat = 1;
	char **cmd;
	static  char *environ[256] = {0};
	while (stat == 1)
	{
		displayPrompt();
		get_next_line(0,&buffer);
		cmd = cmd_proce(buffer);
		ft_ex(cmd,env);
		if (!strcmp(cmd[0],"exit"))
			stat = 0;
		free(buffer);
	}
	return 0;
}


