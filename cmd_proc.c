/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:29:14 by oel-bour          #+#    #+#             */
/*   Updated: 2020/01/14 18:29:15 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_table(char **tab)
{
    int i = 0;
    while (tab[i] != NULL)
    {
            printf("%s\n",tab[i]);
            i++;
    }
    
}


void    proc(char **ptr)
{
    char **tab[20];
    int i = 0;
    while (ptr[i] != NULL)
    {
        tab[i] = ft_split(ptr[i],'|');
        i++;
    }
    print_table(tab[0]);
}

int  is_cmd(char * sem)
{
    int i = 0;
    while (!strcmp(sem,commands[i++]))
        ;
    if (i <= 6)
        return i;
    else
        return 0;    
}

int  is_red(char * sem)
{
    int i = 0;
    while (!strcmp(sem,redirection[i++]))
        ;
    if (i <= 4)
        return i;
    else
        return 0;    
}
void    print_struct(t_cmd d)
{
    print_table(d.main_cmd);
}
int main(int argc,char **argv)
{
    if (argc == 1)
    {
        return 0;
    }
    argv[1] = ft_strtrim(argv[1],"\'\"");
    
    char **sem = ft_split(argv[1],' ');
    t_cmd tab[10];
    int i = 0;
    int j= 0;
    int k = 0;
    while (sem[i])
    {
        if (is_cmd(sem[i]))
        {
            tab[j].main_cmd[k] = strdup(sem[i]);
            while (!strcmp(sem[i],";"))
            {
                if (!(tab[j].red = (is_red(sem[i]))))
                    tab[j].main_cmd[k] = strdup(sem[i]);
                else
                {
                    k++;
                    tab[j].file = strdup(sem[i]);
                }
                
                k++;
                i++;
            }
            


        }
    i++;
    }
// print_struct(tab[0]);
    return 0;
}