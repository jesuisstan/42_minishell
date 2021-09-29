#include "../../inc/minishell.h"

int	ms_check_builtins(char *key)
{
	if (!ft_strcmp(key, "echo"))
		return (0);
	else if (!ft_strcmp(key, "cd"))
		return (0);
	else if (!ft_strcmp(key, "pwd"))
		return (0);
	else if (!ft_strcmp(key, "export"))
		return (0);
	else if (!ft_strcmp(key, "unset"))
		return (0);
	else if (!ft_strcmp(key, "env"))
		return (0);
	else if (!ft_strcmp(key, "exit"))
		return (0);
	else
		return(1);
}





void	run_command(t_msh *msh, t_cmnd *cmnd)
{
	char	**paths;
	char	*name;

//	if (!cmnd->lst_arg)
//		exit (0);
	paths = get_path(msh);
	name = cmnd->arg[0];
	while (gen_next_path(cmnd->arg, paths, name))
	{
		execve(cmnd->arg[0], cmnd->arg, msh->envp_m);
	}
	exit(127);
}

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;
	t_cmnd	cmnd;
	char **path;
	int i = 0;
	
	msh.cmnd = &cmnd;
	(void)argc;
	msh.cmnd->arg = ft_split("ls -la", ' ');

	msh.envp_l = ms_clone_envp(envp);
	ms_cp_envp(&msh, envp);
	run_command(&msh, msh.cmnd);
//	while(path[i++])
//		printf("%s\n", path[i]);
//	print_env_l(msh.envp_l);
	return (0);
}