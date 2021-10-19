/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envp_m_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshmelly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:18 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/17 18:58:18 by mshmelly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
**	@brief		funtion finded the key in envp possable leaks
**
**	@param		arr pointer two dimensional array
**	@return		copy 
*/
char	*ms_find_envp_m(char **envp, char *key)
{
	int		i;
	int		i1;
	char	*temp;

	i = 0;
	temp = NULL;
	if (envp == NULL || (*envp == NULL))
		return (NULL);
	while (envp[i])
	{
		i1 = 0;
		if (!ft_strncmp(envp[i], key, ft_strlen(key)))
		{
			while (envp[i][i1] != '=' && envp[i][i1] != 0)
				i1++;
			if (i1 == (int)ft_strlen(key))
			{
				temp = ft_strdup(envp[i] + i1 + 1);
				return (temp);
			}
		}
		i++;
	}
	return (NULL);
}

int	ms_find_envp_m_and_replace_val(char **envp, char *key, char *val)
{
	int		i;
	int		i1;

	i = 0;
	while (envp[i])
	{
		i1 = 0;
		if (!ft_strncmp(envp[i], key, ft_strlen(key)))
		{
			while (envp[i][i1] != '=' && envp[i][i1] != 0)
				i1++;
			envp[i][i1 + 1] = '\0';
			envp[i] = ft_strjoin(envp[i], val);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ms_cp_envp(t_msh *msh, char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = ms_arrlen(envp);
	msh->envp_m = ms_malloc_x(sizeof(msh->envp_m) * len + 1);
	while (len)
	{
		msh->envp_m[i] = ft_strdup(envp[i]);
		i++;
		len--;
	}
	msh->envp_m[i] = NULL;
	return ;
}

//int	main(int agrc, char **argv, char **envp)
//{
//	t_msh	*msh;

//	msh = ms_malloc_x(sizeof(t_msh));
//	msh->envp_l = ms_clone_envp(envp);
//	printf("%s\n", ms_find_envp(&msh->envp_l, argv[1]));
//	return (0);
//}
