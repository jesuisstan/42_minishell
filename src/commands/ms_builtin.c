#include "../../inc/minishell.h"

void	ms_builtins(t_msh *msh, t_cmd *cmd)
{
	int	status;
	
	status = 0;
	if (!ft_strcmp(cmd->cmd[0], "echo"))
		status = ms_echo(cmd->cmd);
	else if (!ft_strcmp(cmd->cmd[0], "cd"))
		status = ms_cd(msh, cmd->cmd);
	else if (!ft_strcmp(cmd->cmd[0], "pwd"))
		status = ms_pwd();
	else if (!ft_strcmp(cmd->cmd[0], "export"))
		status = ms_export(msh, cmd->cmd);
	else if (!ft_strcmp(cmd->cmd[0], "unset"))
		status = ms_unset(msh, cmd->cmd);
	else if (!ft_strcmp(cmd->cmd[0], "env"))
		status = ms_env(msh->envp_l);
	else if (!ft_strcmp(cmd->cmd[0], "exit"))
		status = ms_exit(cmd->cmd);
	else
		ft_putendl_fd("WTF?", 1);
	return ;
}