/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:52:00 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/28 12:21:11 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int cd(char *s)
{

    char *p;
    char buffer[100];
    char *h;

    h = var("HOME");
    if (s == NULL)
        s = h;
    if (s[0] == '~' && s[1] == '/')
    {
        strcpy(buffer,h);
        strcat(buffer,s + 2);
    }
    else if (s[0] == '~')
    {
        strcpy(buffer,h);
        strcat(buffer,s + 1);
    }
    else
        strcpy(buffer,s);
    if (chdir(buffer) != 0)
    {
        printf("cd: no such file or directory: %s\n",buffer);
        return 0;
    }
    return 1;
}

int     pwd(int fd)
{
    char buffer[1000];
    memset(buffer,0,100);
    char *h;
    h = getcwd(buffer,100);
    if (h != NULL)
    {
        write(fd,buffer,strlen(buffer));
        write(fd,"\n",1);
    }
    return 1;
}

int     count(char **argv)
{
    int i = 0;
    while (argv[i])
        i++;
    return i;
}

void    print_echo(char **argv, int i,int argc)
{
    while (argv[i])
    {
        write(1,argv[i],strlen(argv[i]));
        if (i != argc - 1)
            write(1," ",1);
        i++;
    }
}

int echo(char **argv)
{
    int argc = count(argv);
    if (argc == 1)
        write(1,"\n",1);
    else if (argc > 2 && strcmp(argv[1],"-n") == 0)
        print_echo(argv,2,argc);
    else
    {
        print_echo(argv,1,argc);
        write(1,"\n",1);
    }
    return (0);
}

t_command   *creat_(char *str,int what)
{
    t_command *tmp = (t_command*)malloc(sizeof(t_command));
    if (tmp == NULL)
        return NULL;
    tmp->str = strdup(str);
    tmp->what = what;
    tmp->next = NULL;
    return tmp;
}
void    push_back_ex(t_env **head,t_env *data,char **s)
{
    t_env *counter = *head;

    if (counter == NULL)
    {
        *head = data;
        return;
    }
    if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0)
    {
        ft_free(&counter->value);
        counter->value = ft_strdup(s[1]);
        return ;
    }
    while (counter->next)
    {
        if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0)
        {
            ft_free(&counter->value);
            counter->value = ft_strdup(s[1]);
            return ;
        }
        counter = counter->next;
    }
    if (ft_strncmp(s[0], counter->variable, ft_strlen(s[0])) == 0)
    {
        ft_free(&counter->value);
        counter->value = ft_strdup(s[1]);
        return ;
    }
    counter->next = data;
}

void    push_back(t_env **head,t_env *data)
{
    t_env *counter = *head;
    if (counter == NULL)
    {
        counter->next = data;
        return;
    }
    
    while (counter->next)
        counter = counter->next;
    counter->next = data;
}
void    print(t_command *head)
{
    t_command *counter = head;
    while (counter)
    {
        // printf("%s\n",counter->str);
        // printf("%d\n",counter->what);
        counter = counter->next;
    }
    
}
int    export(char **arg)
{
    char *s;

    s = "bash: export: `=': not a valid identifier\n";
    if (arg[1] == NULL)
        env_declarex(environt);
    else
    {
        t_env *data= (t_env *)malloc(sizeof(t_env));
        if (arg[1][0] == '=')
        {
            write(1, s, strlen(s));
            return 1;
        }
        else if (ft_strchr(arg[1], '=') == NULL)
            return 1;
        else
        {
            char **s = ft_split(arg[1], '=');
            data->variable = strdup(s[0]);
            puts(s[0]);
            if (s[1] == NULL)
                data->value = strdup("");
            else
                data->value = strdup(s[1]);
            data->next = NULL;
            push_back_ex(&environt, data,s);
        }
        return 0;
    }
    return 1;
}

t_command **get_semi(t_command *head, int *n)
{
    t_command *counter;
    t_command **tab;
    int i;

    if (head == NULL)
        return (NULL);
    counter = head;
    tab = (t_command**)calloc(10,sizeof(t_command*));
    i = 1;
    if (head->what != SEMICOL)
        tab[0] = head;
    while (counter)
    {
        if (counter->what == SEMICOL)
        {
            tab[i] = counter->next;
            i++;
        }
        counter = counter->next;
    }
    *n = i;
    return tab;
}

t_command **get_pipe(t_command *head,int *n)
{
    t_command **tab;
    int i;

    if (head == NULL)
        return NULL;
    tab = NULL;
    tab = (t_command**)calloc(10,sizeof(t_command*));
    i = 1;
    tab[0] = head;
    while (head != NULL)
    {
        if (head->what == SEMICOL)
            break;
        if (head->what == PIPE)
        {
            tab[i] = head->next;
            i++;
        }
        head = head->next;
    }
    *n = i;
    return tab;
}

void    ft_free(char **arg)
{
    if (arg && *arg)
        free(*arg);
    *arg = NULL;
}

void    ft_free_star(char **arg)
{
    int i;

    if (arg == NULL)
        return ;
    i = 0;
    while (arg[i])
    {
        ft_free(&arg[i]);
        i++;
    }
}

int  is_cmd(char * sem)
{
	int i = 0;
	while (i < 8)
	{
		if (!strcmp(sem, commands[i]))
			return (1);
		i++;
	}
	return (0);
}


int		unset(char **arg)
{
	int		i;
	t_env *tmp;
    t_env **cmd;
    t_env *cmdx;
    char *var;

    cmd = &environt;
    cmdx = *cmd;
    if (arg[1] == NULL)
        return -1;
    if (strrchr(arg[1],'='))
    {
        //printf("bash: unset: `%s': not a valid identifier", arg[1]);
        puts("bash: unset: `");
        puts(arg[1]);
        puts("': not a valid identifier");
        return (0);
    }
    var = arg[1];
    if (cmdx != NULL && ft_strncmp(var, cmdx->variable, ft_strlen(var)) == 0)
    {
        *cmd = cmdx->next;
        free(cmdx);
        return 0;
    }
	i = 0;
	while (cmdx && ft_strncmp(var, cmdx->variable, ft_strlen(var)) != 0)
	{
        tmp = cmdx;
		cmdx = cmdx->next;
	}
    if (cmdx == NULL)
        return -1;
    tmp->next = cmdx->next;
    free(cmdx);
	return (0);
}

char		*var(char *s)
{
	int		i;
	t_env *tmp;
    t_env *cmd;
    char *var;

    cmd = environt;
    if (s == NULL)
        return (0);
	i = 0;
	while (cmd)
	{
		if (ft_strncmp(s, cmd->variable, ft_strlen(s)) == 0)
			return (cmd->value);
		cmd = cmd->next;
	}
	return (0);
}

void	signal_x(int f)
{
	ft_putstr_fd("\nroot@e120e15p3 # ", 1);
}


// void    ft_free_cmd(t_command)


int	env_var(t_env *ls)
{
	t_env *tmp;
	if (ls == NULL)
		return 0;
	tmp = ls;
	while (tmp != NULL)
	{
		printf("%s=%s\n", tmp->variable, tmp->value);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_lstadd_back_var(t_env **alst, t_env *new)
{
	t_env	*tmp;

	tmp = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}


void    ft_free_void(void **arg)
{
    if (arg && *arg)
        free(*arg);
    *arg = NULL;
}

void    ft_free_void_star(void **arg)
{
    int i;

    if (arg == NULL)
        return ;
    i = 0;
    while (arg[i])
    {
        ft_free_void(&arg[i]);
        i++;
    }
}