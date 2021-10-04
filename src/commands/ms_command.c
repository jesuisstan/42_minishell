#include "../../inc/minishell.h"

static void		ms_no_such(char *name)
{
	ft_putstr_fd(MSH, STDERR_FILENO);
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
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
		return(0);
}

void	ms_command(t_msh *msh, t_cmd *cmd)
{
	char	**paths;
	char	*name;

//	if (!cmnd->lst_arg)
//		exit (0);
	paths = get_path(msh);
	name = cmd->arg[0];
	if (is_builtins(cmd->arg[0]))
	{
//		ft_putendl_fd("\nPIZDA", msh->old_out);
		ms_builtins(msh, cmd);
//		exit(g_status);
		exit(0);
	}
	else
	{
		while (gen_next_path(cmd->arg, paths, name)) {
			execve(cmd->arg[0], cmd->arg, msh->envp_m);
//		if (errno != 2)
//			ft
		}
	}
	ms_no_such(name);
	exit(127);
}

//int	main(int argc, char **argv, char **envp)
//{
//	t_msh	msh;
//	t_cmd	cmd;
//	char **path;
//	int i = 0;
//
//	msh.cmd = &cmd;
//	(void)argc;
//	msh.cmd->arg = ft_split("ls a", ' ');
//
//	msh.envp_l = ms_clone_envp(envp);
//	ms_cp_envp(&msh, envp);
//	ms_command(&msh, msh.cmd);
///	while(path[i++])
///		printf("%s\n", path[i]);
///	print_env_l(msh.envp_l);
//	return (0);
//}