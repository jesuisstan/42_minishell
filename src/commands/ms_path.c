#include "../../inc/minishell.h"
//
// Created by Артём Серебряков on 28.09.2021.
//
int	is_path(char *name)
{
	while (*name && !ft_isalnum(*name))
		if (*name++ == '/')
			return (1);
	return (0);
}

char	**get_path(t_msh *msh)
{
	char 	*lst_path;
	char	**paths;
	
	lst_path = ms_find_envp_l(&msh->envp_l, "PATH");
	printf("PATH	%s\n", lst_path);
	paths = ft_split(lst_path, ':');
	return (paths);
}

int	gen_next_path(char **argv, char **paths, char *name)
{
	static int	i;
	char *tmp;
	
	if (i > 1)
		free(argv[0]);
	if (i > ms_arrlen(paths) || (!paths[0] && !is_path(name)))
	{
		i = 0;
		argv[0] = name;
		return (0);
	}
	if (!i && !is_path(name))//name[0] == '/')
		i++;
	if (i)
	{
		tmp = ft_strjoin(paths[i - 1], "/");
		argv[0] = ft_strjoin(tmp, name);
		if (!tmp || !argv[0])
			{
			perror(NULL);
			exit(1);
			} // или exit(errno);
		free(tmp);
	}
	i++;
	return (1);
	
}