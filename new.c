#include "minishell.h"
int   ft_ex(char **arg,char **env,int fdx)
{
	int pid;
	int status;

	if ((pid = fork()) == -1)
	{
		perror("fork");
		return 1;
	}
	else if (pid == 0)
	{
        dup2(fdx,1);
		if (execve(arg[0],&arg[0],env))
			perror("exceve");
		return 1;
	}
	else 
		wait(&status);
	return 0;
}
int  is_cmd(char * sem)
{
    int i = 0;
    while (i < 6)
    {
        if (!strcmp(sem,commands[i]))
            return i + 1;
        i++;
    }
    return 0;     
}

int  is_not(char * sem)
{
    int i = 0;
    while (i < 2)
    {
        if (!strcmp(sem,not[i]))
            return i + 1;
        i++;
    }
    return 0;    
}

int  is_red(char * sem)
{
    int i = 0;
    while (i < 3)
    {
        if (!strcmp(sem,redirection[i++]))
            return i + 1;
        i++;
    }
    return 0;    
}


int     file_open(char *file,int r)
{
    int fd;
    if (r == 3)
    {
        fd = open(file,O_WRONLY | O_CREAT);
    }
    else if (r == 4)
    {
        fd = open(file,O_APPEND|O_WRONLY| O_CREAT);
    }
    else
    {
        return 1;
    }
    
    return fd;
}

void init(char **cmd,int num)
{
    int i = 0;
    while (i < num)
    {
        cmd[i] = NULL;
        i++;
    }
}
int     main(int argc,char **argv)
{
    if (argc == 1)
    {
        printf("supply arguments\n");
        return 1;
    }
    char **arg = ft_split(ft_strtrim(argv[1],"\"\'"),' ');
    char **cmd = malloc(sizeof(char *) * 10);
    init(cmd,10);
    int r = 0;
    if (!is_cmd(arg[0]))
    {
        perror("not a cmd\n");
        return 1;
    }
    else
    {
        cmd[0] = strdup(arg[0]);
    }
    int i = 1;
    while (arg[i])
    {
        if ((r = is_red(arg[i])))
        {
            i++;
            if (arg[i] == NULL)
            {
                perror("no file supplied\n");
                return 1;
            }
            else 
            {
                // printf(">>>>%d\n",r);
                //  puts(cmd[0]);
                //     puts(cmd[1]);
                //     puts(cmd[2]);
                ft_ex(cmd,NULL,file_open(arg[i],r));
                return 0;
            }
        }
        else
        {
            cmd[i] = strdup(arg[i]);
        }
        i++;
    }
    // puts(cmd[0]);
    // puts(cmd[1]);
    // printf("%s\n",cmd[2]);
    ft_ex(cmd,NULL,1);
    return 0;
}
    

int     some(char **arg)
{
    char **cmd = malloc(sizeof(char *) * 10);
    int r;
    if (!is_cmd(arg[0]))
    {
        perror("not a cmd\n");
        return 1;
    }
    else
    {
        cmd[0] = strdup(arg[0]);
    }
    int i = 1;
    while (arg[i])
    {
        if ((r = is_red(arg[i])))
        {
            i++;
            if (arg[i] == NULL)
            {
                perror("no file supplied\n");
                return 1;
            }
            else 
            {
                ft_ex(cmd,NULL,file_open(arg[i],r));
                return 0;
            }
        }
        else
        {
            cmd[i] = strdup(arg[i]);
        }
        i++;
    }
    ft_ex(cmd,NULL,1);
    return 0;
}