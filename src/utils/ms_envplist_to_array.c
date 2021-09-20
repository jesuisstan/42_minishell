// convert envp_l_list to 2D-array

#include "../../inc/minishell.h"

static size_t	ms_lstsize_envp(t_envp **envp_l)
{
	size_t	i;
	t_envp	*tmp;

	if (!envp_l || !(*envp_l))
		return (-1);
	tmp = *envp_l;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char **ms_envplist_to_array(t_envp **envp_l)
{
	int		size;
	int		i;
	char	**envp_arr;

	if(*envp_l == NULL)
		return (NULL);
	size = ms_lstsize_envp(envp_l);
	envp_arr = malloc(sizeof(char *) * size + 1);
	if (!envp_arr)
		return (NULL);
	i = 0;
	while (*envp_l && (size != 0))
	{
		envp_arr[i] = ft_strdup((*envp_l)->content);
		i++;
		size--;
		*envp_l = (*envp_l)->next;
	}
	envp_arr[i] = NULL;
	return (envp_arr);
}
