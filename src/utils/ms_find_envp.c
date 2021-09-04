#include "../../inc/minishell.h"

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
		if (!ft_strncmp(key, envp[i], ft_strlen(key)))
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
