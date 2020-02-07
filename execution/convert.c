/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:35:46 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/07 11:55:37 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		help_convert2(t_command *counter)
{
	char	**arg;
	t_env	*node;

	if (counter->str != NULL && counter->str[0] != '=' &&
	ft_strrchr(counter->str, '='))
	{
		node = (t_env*)malloc(sizeof(t_env));
		arg = ft_split(counter->str, '=');
		node->variable = ft_strdup(arg[0]);
		node->value = ft_strdup(arg[1]);
		node->next = NULL;
		push_back_ex(&g_variables, node, arg);
		ft_free_star(arg);
		return (1);
	}
	return (0);
}

char	*help_convert(t_command *head)
{
	t_command	*counter;
	int			r;

	counter = head;
	if (!(r = help_convert2(counter)) && counter->str != NULL &&
	!ft_strcmp("export", counter->str))
	{
		if (counter->next != NULL && counter->next->next != NULL &&
		counter->next->next->str != NULL &&
		!is_string(counter->next->next->str))
		{
			ft_printf("bash: export: `%s': not a valid identifier\n",
			counter->next->next->str);
			g_status = 1;
			return (NULL);
		}
	}
	else if (r == 1)
		return (NULL);
	return (counter->str);
}

char	**help_convert1(t_command *counter)
{
	char	*tmp;
	int		i;

	g_argv = (char**)ft_calloc(4096, sizeof(char*));
	i = 0;
	while (counter)
	{
		if (counter->what == PIPE || counter->what == SEMICOL)
			break ;
		if (do_somein_1(&counter) == -1 || do_someout_1(&counter) == -1)
			return (NULL);
		if (counter->what == COMMAND)
		{
			to_lower(&counter);
			if (help_convert(counter) == NULL || !(tmp = path(counter->str)))
				return (NULL);
			g_argv[i] = ft_strdup(tmp);
			free(tmp);
		}
		else
			g_argv[i] = ft_strdup(counter->str);
		counter = counter->next;
		i++;
	}
	g_argv[i] = NULL;
	return (g_argv);
}

char	**convert(t_command *head)
{
	t_command *counter;

	counter = head;
	if (counter != NULL && counter->what == REDOUT)
	{
		if (!do_someout(&counter))
			return (NULL);
		else
			return (g_argv);
	}
	if (counter != NULL && counter->what == REDIN)
	{
		if (!do_somein(&counter))
			return (NULL);
		else
			return (g_argv);
	}
	return (help_convert1(counter));
}
