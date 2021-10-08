#include "../../inc/minishell.h"

void	ms_oldpwd(t_msh *msh, char *oldpwd)
{
	int	i;

	i = 0;
	if (msh->envp_m == NULL)
		return ;
	if (!ms_find_envp_l_and_replace_val(&msh->envp_l, "OLDPWD", oldpwd))
	{
		while (msh->envp_m[i])
			i++;
		msh->envp_m[i] = ft_strjoin("OLDPWD=", oldpwd);
		msh->envp_m[i + 1] = NULL;
		return ;
	}
	return ;
}

int	ms_new_pwd(t_msh *msh)
{
	char	*pwd;

	pwd = getcwd(NULL, 2048);
	if (!pwd)
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (1);
	}
	else
	{
		if (msh->envp_l == NULL)
			return (1);
		ms_find_envp_l_and_replace_val(&msh->envp_l, "PWD", pwd);
		return (0);
	}
	free(pwd);
	return (0);
}
