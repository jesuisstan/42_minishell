#include "../../inc/minishell.h"

void	ms_builtins(t_msh *msh, t_cmd *cmd)
{
	if (!ft_strncmp(cmd->cmd[0], "echo", 4))
		g_status.exit = ms_echo(cmd->cmd);
	else if (!ft_strncmp(cmd->cmd[0], "cd", 2))
		g_status.exit = ms_cd(msh, cmd->cmd);
	else if (!ft_strncmp(cmd->cmd[0], "pwd", 3))
		g_status.exit = ms_pwd();
	else if (!ft_strncmp(cmd->cmd[0], "export", 6))
		g_status.exit = ms_export(msh, cmd->cmd);
	else if (!ft_strncmp(cmd->cmd[0], "unset", 5))
		g_status.exit = ms_unset(msh, cmd->cmd);
	else if (!ft_strncmp(cmd->cmd[0], "env", 3))
		g_status.exit = ms_env(msh->envp_l);
	else if (!ft_strncmp(cmd->cmd[0], "exit", 4))
		g_status.exit = ms_exit(msh, cmd->cmd);
	else
		ft_putendl_fd("WTF?", 1);
	return ;
}

int	is_builtins(char *key)
{
	if (key == NULL)
		return (0);
	else if (!ft_strncmp(key, "echo", 4))
		return (1);
	else if (!ft_strncmp(key, "cd", 2))
		return (1);
	else if (!ft_strncmp(key, "pwd", 3))
		return (1);
	else if (!ft_strncmp(key, "export", 6))
		return (1);
	else if (!ft_strncmp(key, "unset", 5))
		return (1);
	else if (!ft_strncmp(key, "env", 3))
		return (1);
	else if (!ft_strncmp(key, "exit", 4))
		return (1);
	else
		return (0);
}
