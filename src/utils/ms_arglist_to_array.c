// convert arg_list to 2D-array

#include "../../inc/minishell.h"

static size_t	ms_lstsize_arg(t_arg *arg)
{
	size_t	i;
	t_arg	*tmp;

	if (!arg)
		return (-1);
	tmp = arg;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char **ms_arglist_to_array(t_arg *arg, int size)
{
	int		sz;
	int		i;
	char	**arg_arr;
	t_arg	*tmp;

	tmp = arg;
	if (size <= 0)
		sz = ms_lstsize_arg(tmp);
	else
		sz = size;
	arg_arr = malloc(sizeof(char *) * size + 1);
	if (!arg_arr)
		return (NULL);
	i = 0;
	while (tmp && (size != 0))
	{
		arg_arr[i] = ft_strdup(tmp->arg_pure);
		i++;
		size--;
		tmp = tmp->next;
	}
	arg_arr[i] = NULL;
	return (arg_arr);
}
