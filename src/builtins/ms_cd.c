#include "../../inc/minishell.h"

static char	*ms_find_home(t_envp **lst)
{
	t_envp	*tmp;
	char	*cp_value;

	cp_value = NULL;
	if (lst && (*lst))
	{
		tmp = *lst;
		while (tmp)
		{
			if (!ft_strcmp(tmp->key, "HOME"))
			{
				cp_value = ft_strdup(tmp->value);
				return (cp_value);
			}
			tmp = tmp->next;
		}
	}
	return (NULL);
}

static int	ms_not_set(void)
{
	ft_putstr_fd (MSH, STDERR_FILENO);
	ft_putendl_fd ("cd : HOME not set", STDERR_FILENO);
	return (1);
}

int	ms_change_dir(t_msh *msh, char *path)
{
	char	*oldpwd;

	oldpwd = getcwd(NULL, 2048);
	if (!oldpwd)
		oldpwd = ms_find_envp_l(&msh->envp_l, "HOME");
	if (chdir(path))
	{
		ft_putstr_fd(MSH, STDERR_FILENO);
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		free(oldpwd);
		return (1);
	}
	else
	{
		free(oldpwd);
		return (ms_new_pwd(msh));
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
		home = ms_find_home(&msh->envp_l);
		if (!home)
		{
			return (ms_not_set());
		}
		res = ms_change_dir(msh, home);
		free(home);
		return (res);
	}
}
