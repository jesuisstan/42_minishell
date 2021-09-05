#include "../../inc/minishell.h"

static int	ms_not_set(void)
{
	ft_putstr_fd (MSH, STDERR_FILENO);
	ft_putendl_fd ("cd : HOME not set", STDERR_FILENO);
	return (1);
}

static int	sm_choose_dir(char *path, t_msh *msh)
{
	char	*oldpwd;
	return(0);

}

static int	ms_choose_dir(char *path, t_msh *msh)
{
	char	*oldpwd;

	(void)path;
	if(!(oldpwd = getcwd(NULL, 2048)))
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (1);
	}
	if(chdir(path))
	{
		ft_putstr_fd(MSH, STDERR_FILENO);
		ft_putstr_fd("cd:", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (1);
	}
	else
	{
		msh->path_oldpwd = ft_strdup(oldpwd);
	}
	//printf("getcwd :%s\n", getcwd(NULL, 2048));
	//printf("chdir :%d\n", chdir(path));
	//printf("getcwd :%s\n", getcwd(NULL, 2048));
	return (0);
}

static int	ms_cd_oldpwd(t_msh *msh) // пока не юзаем)
{
	char	*value;

	value = ms_find_envp(msh->cp_envp, "OLDPWD");
	if (!value)
	{
		ft_putstr_fd(MSH, STDERR_FILENO);
		ft_putendl_fd("cd : OLDPWD not set", STDERR_FILENO);
		return(1);
	}
	else
	{
		return(sm_choose_dir(value, msh));
	}
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
		res = 0; /////////////////////////
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
	//printf("%s\n", ms_find_envp(envp, "OLDPWD"));
	// ms_oldpwd(&msh);
	ms_choose_dir("/Users/mshmelly/21/", &msh);

	printf("%s\n", ms_find_envp(envp, "OLDPWD"));
	printf("%s\n", msh.path_oldpwd);
	
	return (0);
}