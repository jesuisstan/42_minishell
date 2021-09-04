#include "../../inc/minishell.h"

static int	ms_not_set(void)
{
	ft_putstr_fd (MSH, STDERR_FILENO);
	ft_putendl_fd ("cd : HOME not set", STDERR_FILENO);
	return (1);
}

int	ms_cd(char **envp, t_msh *msh)
{
	char	*home;
	int		res;
	
	home = NULL;
	if (ms_arrlen(envp) > 1)
	{
		return(0);
	}
	else
	{
		home = ms_find_envp(envp, "HOME");
		if (!home)
			return (ms_not_set());
		res = 
		free(home);
		return (res);
	}
	return (0);
}



int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;
	int	i = 0;

	ms_cp_envp(envp, &msh);
	
	return (0);
}