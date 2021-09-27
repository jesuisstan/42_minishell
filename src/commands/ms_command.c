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

void	run_command(t_msh *msh)git log
{
	char	**paths;
	char	*name;
	
	if (msh->cmnd->lst_arg)
}