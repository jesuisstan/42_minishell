/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshmelly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:17 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/17 18:58:17 by mshmelly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_path(char *name)
{
	while (*name && !ft_isalnum(*name))
		if (*name++ == '/')
			return (1);
	return (0);
}

static char	**get_path(t_msh *msh)
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
		return (name);
	if (!paths)
		return (NULL);
	while (paths[i])
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
