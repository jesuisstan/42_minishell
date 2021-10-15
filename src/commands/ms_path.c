#include "../../inc/minishell.h"

int	is_path(char *name)
{
	while (*name && !ft_isalnum(*name))
		if (*name++ == '/')
			return (1);
	return (0);
}

char	**get_path(t_msh *msh)
{
	char	*lst_path;
	char	**paths;

	lst_path = ms_find_envp_l(&msh->envp_l, "PATH");
	if (!lst_path)
		return (NULL);
	paths = ft_split(lst_path, ':');
	return (paths);
}

char	*done_path(t_msh *msh, char *name)
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	paths = get_path(msh);
	if (is_path(name))
		return(name);
	if (!paths)
		return (NULL);
	while(paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, name);
		free(tmp);
		if (!access(path, F_OK | X_OK))
			return (path);
		free(paths[i]);
		i++;
	}
	free(paths);
	return (NULL);
}


int	gen_next_path(char **argv, char **paths, char *name)
{
	static int	i;
	char		*tmp;

	if (i > 1)
		free(argv[0]);
	if (i > ms_arrlen(paths) || (!paths[0] && !is_path(name)))
	{
		i = 0;
		argv[0] = name;
		return (0);
	}
	if (!i && !is_path(name))
		i++;
	if (i)
	{
		tmp = ft_strjoin(paths[i - 1], "/");
		argv[0] = ft_strjoin(tmp, name);
		if (!tmp || !argv[0])
		{
			perror(NULL);
			exit(errno);
		}
		free(tmp);
	}
	i++;
	return (1);
}
