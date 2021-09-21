// convert arg_list to 2D-array

#include "../../inc/minishell.h"

static size_t	ms_lstsize_arg(t_arg **arg)
{
	size_t	i;
	t_arg	*tmp;

	if (!arg || !(*arg))
		return (-1);
	tmp = *arg;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char **ms_arglist_to_array(t_arg **arg)
{
	int		size;
	int		i;
	char	**arg_arr;

	if(*arg == NULL)
		return (NULL);
	size = ms_lstsize_arg(arg);
	arg_arr = malloc(sizeof(char *) * size + 1);
	if (!arg_arr)
		return (NULL);
	i = 0;
	while (*arg && (size != 0))
	{
		arg_arr[i] = ft_strdup((*arg)->arg_pure);
		i++;
		size--;
		*arg = (*arg)->next;
	}
	arg_arr[i] = NULL;
	return (arg_arr);
}
