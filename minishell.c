#include "minishell.h"

int   echo(char **arg);

void    displayPrompt()
{
	write(1,"AGI>>",5);
}

int  is_cmd(char * sem)
{
    int i = 0;
    while (i < 6)
	{
		if (!strcmp(sem,commands[i]))
			return 1;
		i++;
	}
    return 0;    
}

void sig()
{
	printf("\n");
}
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
			signal(SIGQUIT,sig);
		if (execve(arg[0],&arg[0],env))
			perror("exceve");
		return 1;
	}
	else 
		wait(&status);
	printf(">>>>%d\n",status);
	return 0;
}
char *argx[3] = {"echo","-n",NULL};
void	exit_()
{
	
}
char   **cmd_proce(char *buffer)
{  
	char **cmd = ft_split(buffer,' ');
	if (*cmd == NULL)
		return argx;
	if (is_cmd(cmd[0]))
	{
		if (!strcmp(cmd[0],"cd"))
			cd(cmd[1]);
		if (!strcmp(cmd[0],"pwd"))
			pwd();
		if (!strcmp(cmd[0],"pwd"))
			exit_();
		//return cmd;
		return NULL;
	}
	else 
	{
		char *c = strdup("/bin/");
		strcat(c,cmd[0]);
		cmd[0] = strdup(c);
	}
	return cmd;
}
int main(int argc, char *argv[])
{
	char *buffer;
	char *line;
	char **env;
	int stat = 1;
	char **cmd;

	//void    push_back1(&head,"echo",COMMAND);
	static  char *environ[256] = {0};
	signal(SIGINT,sig);

	while (stat == 1)
	{

		displayPrompt();
		get_next_line(0,&buffer);
		printf("%s",buffer);
		cmd = cmd_proce(buffer);
		if (cmd != NULL)
		{
			if (!strcmp(cmd[0],"exit"))
				stat = 0;
			ft_ex(cmd,env);
		}
		free(buffer);
		buffer = NULL;
	}
	return 0;
}


