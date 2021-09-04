#include "../../inc/minishell.h"

void	ms_cp_envp(char **envp, t_msh *msh)
{
	int	i = 0;
	int	i1 = 0;
	int	len;

	len = ms_arrlen(envp);
	msh->cp_envp = ms_malloc_x(sizeof(msh->cp_envp) * len);
	while (len)
	{
		msh->cp_envp[i] = ft_strdup(envp[i]);
		i++;
		len--;
	}
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;
	int	i = 0;

	ms_cp_envp(envp, &msh);
	while (msh.cp_envp[i])
	{
		printf("%s\n", msh.cp_envp[i]);
		i++;
	}
	return (0);
}
