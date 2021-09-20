#include "../../inc/minishell.h"

static int	ms_not_set(void)
{
	ft_putstr_fd (MSH, STDERR_FILENO);
	ft_putendl_fd ("cd : HOME not set", STDERR_FILENO);
	return (1);
}

void	update_envp(t_msh *msh, char *key)
{
	t_list	*tmp;

	tmp = ms_find_envp(&msh->envp_l, key);
	if (tmp)
	{

	}

}

int	ms_oldpwd(char *oldpwd, t_msh *msh)
{
	char	*pwd;
	
	pwd = ft_strjoin("OLDPWD=", oldpwd);
	if (ms_find_envp(msh->cp_envp, "OLDPWD"))
	{
		msh->envp_l->content = pwd;
	}
	else
		lstadd_back_envp(&msh->envp_l, lstnew_envp(pwd));
	return (0);
}


static int	ms_choose_dir(char *path, t_msh *msh)
{
	char	*oldpwd;

	if(!(oldpwd = getcwd(NULL, 2048)))
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (1);
	}
	if(chdir(path) == -1)
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
		ms_oldpwd(oldpwd, msh);
		//msh->path_oldpwd = ft_strdup(oldpwd);
	}

	return (0);
}

static int	ms_cd_oldpwd(t_msh *msh) // пока не юзаем)
{
	char	*value;

	value = ms_find_envp(&msh->envp_l, "OLDPWD");
	if (!value)
	{
		ft_putstr_fd(MSH, STDERR_FILENO);
		ft_putendl_fd("cd : OLDPWD not set", STDERR_FILENO);
		return(1);
	}
	else
	{
		return(0);
		//return(sm_choose_dir(value, msh));
	}
}

int	ms_cd(char **argv, t_msh *msh)
{
	char	*home;
	int		res;
	
	home = NULL;
	if (ms_arrlen(argv) > 1)
	{
		return(0);
		//return(ft_argv_cd());
	}
	else
	{
		home = ms_find_envp(&msh->envp_l, "HOME");
		if (!home)
			return (ms_not_set());
		res = ms_choose_dir(home, msh); /////////////////////////
		free(home);
		return (res);
	}
	return (0);
}



int	main(int agrc, char *argv[], char **envp)
{
	t_msh	*msh;
	msh = ms_malloc_x(sizeof(t_msh));
	msh->envp_l = ms_clone_envp(envp);

	ms_oldpwd("ᕦ(♥_♥)ᕤ", msh);
	//ms_cd(argv, msh);
	//ms_choose_dir("/Users/mshmelly/21/", &msh);
	t_envp *tmp = msh->envp_l;
	while (tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	printf("%s\n", ms_find_envp(&msh->envp_l, "OLDPWD"));
	//printf("%s\n", msh.path_oldpwd);
	
	return (0);
}