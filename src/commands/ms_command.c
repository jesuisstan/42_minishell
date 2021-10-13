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
//		while (gen_next_path(cmd->cmd, paths, name))
//		{
		execve(done_path(msh,cmd->cmd[0]), cmd->cmd, msh->envp_m);// заменить на листы
			if (access(*paths, 0)) //может это убрать нафиг
				exit(127);
//		}
	}
	ms_no_such(name);
	g_status.exit =127;
	exit(g_status.exit);
//	exit(127);
}
