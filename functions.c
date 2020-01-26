/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:52:00 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/26 14:17:10 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int cd(char *s)
{

    char *p;
    char buffer[100];
    char *h;

    h = strdup("/Users/oel-bour/");
    if (s == NULL)
        s = h;
    if ( (p = strstr(s,"~")))
    {
        strcpy(buffer,h);
        strcat(buffer,s + 1);
    }else if ((p = strstr(s,"~/")))
    {
        strcpy(buffer,h);
        strcat(buffer,s + 2);
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

void    push_back1(t_command **head,char *str,int what)
{
    t_command *data = creat_(str,what);

    if (*head == NULL)
    {
        *head = data;
        return;
    }
    else 
    {
        t_command *counter = *head;
        while (counter->next)
        {
            counter = counter->next;
        }
        counter->next = data;
    }

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
    {
        counter = counter->next;
    }
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

// void    env(t_env *head)
// {
//     t_env *counter = head;
//     while (counter)
//     {
//         // printf("%s=%s",counter->key,counter->value);
//         counter = counter->next;
//     }
    
// }

void    export(t_env *head,t_env *data)
{
    push_back(&head,data);
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
	while (i < 6)
	{
		if (!strcmp(sem, commands[i]))
			return 1;
		i++;
	}
	return 0;    
}