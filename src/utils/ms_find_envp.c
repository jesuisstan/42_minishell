#include "../../inc/minishell.h"

/*
**	@brief		funtion finded the key in copy envp
**
**	@param		lst and key envp
**	@return		value
*/

char	*ms_find_envp_l(t_envp **lst, char *key)
{
	t_envp *tmp;

	if (lst && (*lst) && key)
	{
		tmp = *lst;
		while (tmp)
		{
			if (!ft_strcmp(tmp->key, key))
				return (tmp->value);
			tmp = tmp->next;
		}
	}
	return (NULL);
}

/*
**	@brief		funtion finded the key in envp possable leaks
**
**	@param		arr pointer two dimensional array
**	@return		copy 
*/
char	*ms_find_envp(char **envp, char *key)
{
	int		i;
	int		i1;
	char	*temp;

	i = 0;
	i1 = 0;
	temp = NULL;
	while (envp[i])
	{
		i1 = 0;
		if (!ft_strncmp(envp[i], key, ft_strlen(key)))
		{
			while (envp[i][i1] != '=' && envp[i][i1] != 0)
				i1++;
			if (i1 == ft_strlen(key))
			{
				temp = ft_strdup(envp[i] + i1 + 1);
				return (temp);
			}
		}
		i++;
	}
	return (NULL);
}

void	ms_cp_envp(char **envp, t_msh *msh)
{
	int	i = 0;
	int	i1 = 0;
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


//int	main(int agrc, char **argv, char **envp)
//{
//	t_msh	*g_msh;

//	g_msh = ms_malloc_x(sizeof(t_msh));
//	g_msh->envp_l = ms_clone_envp(envp);
//	printf("%s\n", ms_find_envp(&g_msh->envp_l, argv[1]));
//	return (0);
//}