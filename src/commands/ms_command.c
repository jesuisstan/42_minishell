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
	char	**paths;
	char	*name;
	int		err;
	paths = get_path(msh);
	name = cmd->cmd[0];
	if (is_builtins(cmd->cmd[0]))
	{
		ms_builtins(msh, cmd);
		if (cmd->is_fork)
			exit (0); //продумать статус
		return ;
	}
	else
	{
		name = done_path(msh,cmd->cmd[0]);
		execve(done_path(msh,cmd->cmd[0]), cmd->cmd, msh->envp_m);// заменить на листы
		ms_no_such(name);// туту наме нул
		free(name);
		err = errno;
		if (err == 2 || err == 14 || err == 20) //bad address
			exit(127);
		if (err == 13) //Permission denied
			exit(126);
		exit(127);
	}
}
