#include "../../inc/minishell.h"

/*
**	@brief		funtion finded the key in copy envp
**
**	@param		lst and key envp
**	@return		value
*/

char	*ms_find_envp(t_envp **lst, char *key)
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


//int	main(int agrc, char **argv, char **envp)
//{
//	t_msh	*g_msh;

//	g_msh = ms_malloc_x(sizeof(t_msh));
//	g_msh->envp_l = ms_clone_envp(envp);
//	printf("%s\n", ms_find_envp(&g_msh->envp_l, argv[1]));
//	return (0);
//}