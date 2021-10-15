#include "../../inc/minishell.h"

int	ms_cd_oldpwd(t_msh *msh)
{
	char	*value;

	value = ms_find_envp_l(&msh->envp_l, "OLDPWD");
	if (!value)
	{
		ft_putstr_fd(MSH, STDERR_FILENO);
		ft_putendl_fd("cd : OLDPWD not set", STDERR_FILENO);
		return (1);
	}
	else
		return (ms_change_dir(msh, value));
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
		free(pwd);
		return (0);
	}
}
