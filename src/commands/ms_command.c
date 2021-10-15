#include "../../inc/minishell.h"

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
			exit (0); //продумать статус
		return ;
	}
	else
	{
		file = done_path(msh,cmd->cmd[0]);
		if (!file)
			execve(cmd->cmd[0], cmd->cmd, ms_envplist_to_array(msh->envp_l));// заменить на листы
		else
			execve(file, cmd->cmd, ms_envplist_to_array(msh->envp_l));
		err = errno;
		ms_no_such(cmd->cmd[0]);// туту наме нул
		free(file);
		if (err == 13) //Permission denied
			exit(126);
		else if (err == 2 || err == 14 || err == 20) //bad address
			exit(127);
		else
			exit(0);
	}
}
