#include "../../inc/minishell.h"

static int	ms_not_set(void)
{
	ft_putstr_fd (MSH, STDERR_FILENO);
	ft_putendl_fd ("cd : HOME not set", STDERR_FILENO);
	return (1);
}

static int	ms_change_dir(t_msh *msh, char *path)
{
	char	*oldpwd;

	oldpwd = getcwd(NULL, 2048);
	if (!oldpwd)
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (1);
	}
	if (chdir(path))
	{
		ft_putstr_fd(MSH, STDERR_FILENO);
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (1);
	}
	else
	{
		ms_oldpwd(msh, oldpwd);
		free(oldpwd);
		return (ms_new_pwd(msh));
	}
	free(oldpwd);
	return (0);
}

static int	ms_cd_oldpwd(t_msh *msh)
{
	char	*value;

	value = ms_find_envp_m(msh->envp_m, "OLDPWD");
	if (!value)
	{
		ft_putstr_fd(MSH, STDERR_FILENO);
		ft_putendl_fd("cd : OLDPWD not set", STDERR_FILENO);
		return (1);
	}
	else
	{
		return (ms_change_dir(msh, value));
	}
}

static int	change_way(t_msh *msh, char **argv)
{
	char	*cd[2];

	if (argv[1][0] == '-')
		return (ms_cd_oldpwd(msh));
	else if (argv[1][0] == '~')
	{
		cd[0] = "cd";
		cd[1] = NULL;
		return (ms_cd(msh, cd));
	}
	return (ms_change_dir(msh, argv[1]));
}

int	ms_cd(t_msh *msh, char **argv)
{
	char	*home;
	int		res;

	home = NULL;
	if (ms_arrlen(argv) > 1)
	{
		return (change_way(msh, argv));
	}
	else
	{
		home = ms_find_envp_m(msh->envp_m, "HOME");
		if (!home)
			return (ms_not_set());
		res = ms_change_dir(msh, home);
		free(home);
		return (res);
	}
	return (0);
}

//int	main(int argc, char **argv, char **envp)
//{
//	t_msh	msh;
//
//	(void)argc;
//	ms_cp_envp(&msh, envp);
//	ms_cd(&msh, argv);
//	printf("PWD=%s\n", getcwd(NULL, 2048));
//	return (0);
//}
