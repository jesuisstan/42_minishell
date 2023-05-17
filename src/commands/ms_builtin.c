/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: St.Krivtsov <stan.krivtsov@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:17 by mshmelly          #+#    #+#             */
/*   Updated: 2023/05/17 20:06:29 by St.Krivtsov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern int g_status;

void	ms_builtins(t_msh *msh, t_cmd *cmd)
{
	if (!ft_strcmp(cmd->cmd[0], "echo"))
		g_status = ms_echo(cmd->cmd);
	else if (!ft_strcmp(cmd->cmd[0], "cd"))
		g_status = ms_cd(msh, cmd->cmd);
	else if (!ft_strcmp(cmd->cmd[0], "pwd"))
		g_status = ms_pwd();
	else if (!ft_strcmp(cmd->cmd[0], "export"))
		g_status = ms_export(msh, cmd->cmd);
	else if (!ft_strcmp(cmd->cmd[0], "unset"))
		g_status = ms_unset(msh, cmd->cmd);
	else if (!ft_strcmp(cmd->cmd[0], "env"))
		g_status = ms_env(msh->envp_l);
	else if (!ft_strcmp(cmd->cmd[0], "exit"))
		g_status = ms_exit(msh, cmd->cmd);
	return ;
}

int	is_builtins(char *key)
{
	if (key == NULL)
		return (0);
	else if (!ft_strcmp(key, "echo"))
		return (1);
	else if (!ft_strcmp(key, "cd"))
		return (1);
	else if (!ft_strcmp(key, "pwd"))
		return (1);
	else if (!ft_strcmp(key, "export"))
		return (1);
	else if (!ft_strcmp(key, "unset"))
		return (1);
	else if (!ft_strcmp(key, "env"))
		return (1);
	else if (!ft_strcmp(key, "exit"))
		return (1);
	else
		return (0);
}
