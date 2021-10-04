#include "../../inc/minishell.h"

void	ms_builtins(t_msh *msh, t_cmd *cmd)
{
	int	status;
	
	status = 0;
	if (!ft_strcmp(cmd->arg[0], "echo"))
		status = ms_echo(cmd->arg);
	else if (!ft_strcmp(cmd->arg[0], "cd"))
		status = ms_cd(msh, cmd->arg);
	else if (!ft_strcmp(cmd->arg[0], "pwd"))
		status = ms_pwd();
	else if (!ft_strcmp(cmd->arg[0], "export"))
		status = ms_export(msh, cmd->arg);
	else if (!ft_strcmp(cmd->arg[0], "unset"))
		status = ms_unset(msh, cmd->arg);
	else if (!ft_strcmp(cmd->arg[0], "env"))
		status = ms_env(msh->envp_l);
	else if (!ft_strcmp(cmd->arg[0], "exit"))
		status = ms_exit(cmd->arg);
	else
		ft_putendl_fd("WTF?", 1);
	return ;
}