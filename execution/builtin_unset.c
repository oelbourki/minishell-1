/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:36:00 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/07 18:34:55 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		help_unset(char **arg, t_env *cmdx, t_env **cmd)
{
	if (arg[1] == NULL)
		return (1);
	if (ft_strrchr(arg[1], '='))
	{
		ft_printf("bash: unset: `%s': not a valid identifier\n", arg[1]);
		g_status = 1;
		return (1);
	}
	if (cmdx != NULL && ft_strncmp(arg[1], cmdx->variable,
	ft_strlen(arg[1])) == 0)
	{
		*cmd = cmdx->next;
		ft_free(&cmdx->variable);
		ft_free(&cmdx->value);
		free(cmdx);
		return (1);
	}
	return (0);
}

int		unset1(char **arg, t_env *env)
{
	t_env	*tmp;
	t_env	**cmd;
	t_env	*cmdx;
	int		r;

	cmd = &env;
	cmdx = *cmd;
	if ((r = help_unset(arg, cmdx, cmd)))
		return (r);
	while (cmdx && ft_strncmp(arg[1], cmdx->variable,
	ft_strlen(arg[1])) != 0)
	{
		tmp = cmdx;
		cmdx = cmdx->next;
	}
	if (cmdx == NULL)
		return (-1);
	tmp->next = cmdx->next;
	ft_free(&cmdx->variable);
	ft_free(&cmdx->value);
	free(cmdx);
	return (1);
}

int		unset(char **arg)
{
	int r;

	r = unset1(arg, g_environt);
	if ((r != 1) && r == -1)
		return (-1);
	else if (r == 1)
		return (1);
	else
		return (unset1(arg, g_variables));
}
