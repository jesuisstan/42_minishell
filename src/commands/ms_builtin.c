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
		status = ms_exit(msh, cmd->cmd);
	else
		ft_putendl_fd("WTF?", 1);
	return ;
}

int	is_builtins(char *key)
{
	if (!ft_strcmp(key, "echo"))
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
