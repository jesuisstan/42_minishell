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
		paths = get_path(msh);
		file = cmd->cmd[0];//сдвинуть в есле
		file = done_path(msh,cmd->cmd[0]);
		ft_putendl_fd(ft_strjoin(file, "hyeata"),2);
		execve(file, cmd->cmd, ms_envplist_to_array(msh->envp_l));// заменить на листы
		ms_no_such(cmd->cmd[0]);// туту наме нул
		free(file);
		err = errno;
		if (!file)
			ms_no_such(cmd->cmd[0]);
		if (err == 13) //Permission denied
			exit(126);
		else //(err == 2 || err == 14 || err == 20) //bad address
			exit(127);
	}
}
