/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: St.Krivtsov <stan.krivtsov@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:17 by mshmelly          #+#    #+#             */
/*   Updated: 2023/05/17 20:06:34 by St.Krivtsov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern int g_status;

static void	ms_no_such(char *name)
{
	ft_putstr_fd(MSH, STDERR_FILENO);
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
}

void	ms_command(t_msh *msh, t_cmd *cmd)
{
	char	*file;
	int		err;

	if (is_builtins(cmd->cmd[0]))
	{
		ms_builtins(msh, cmd);
		if (cmd->is_fork)
			exit (g_status);
		return ;
	}
	else
	{
		file = done_path(msh, cmd->cmd[0]);
		if (!file)
			execve(cmd->cmd[0], cmd->cmd, ms_envplist_to_array(msh->envp_l));
		else
			execve(file, cmd->cmd, ms_envplist_to_array(msh->envp_l));
		err = errno;
		ms_no_such(cmd->cmd[0]);
		free(file);
		if (err == 13)
			exit(126);
		else
			exit(127);
	}
}
