#include "../../inc/minishell.h"

void	ms_cp_envp(char **envp, t_msh *msh)
{
	int	i = 0;

	int	len;

	len = ms_arrlen(envp);
	msh->cp_envp = ms_malloc_x(sizeof(msh->cp_envp) * len + 1);
	while (len)
	{
		msh->cp_envp[i] = ft_strdup(envp[i]);
		i++;
		len--;
	}
	msh->cp_envp[i] = NULL;
	return ;
}

void	ms_putlst(char **envp, t_msh *msh)
{
	int	i = 0;
	int	len;

	len = ms_arrlen(envp);
	msh->env = ms_malloc_x(sizeof(msh->env) * len + 1);
	while (len)
	{
		msh->env->val = ms_find_envp(envp, ft_strrchr(envp[i], '='));
		i++;
		len--;
		printf("%s\n", msh->env->val);
	}
	msh->env = NULL;
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;
	int	i = 0;

	ms_cp_envp(envp, &msh);
	ms_putlst(envp, &msh);
	while (msh.env)
	{
		printf("%s\n", msh.cp_envp[i]);
		msh.env = msh.env->next;
		i++;
	}
	return (0);
}
