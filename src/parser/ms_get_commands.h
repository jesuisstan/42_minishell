#include "../../inc/minishell.h"

static size_t	get_cmdsize(t_arg **arg)
{
	size_t	i;

	if (!arg || !*arg)
		return (-1);
	i = 0;
	while (*arg)
	{
		*arg = (*arg)->next;
		i++;
		if (ft_strcmp((*arg)->arg_pure, "|") == 0)
		{
			*arg = (*arg)->next;
			break;
		}
	}
	return (i);
}

t_cmd	*ms_get_commands(t_arg *arg)
{
	int		size;
	int		i;
	char	**arg_arr;
	t_arg	*tmp;
	t_cmd	*cmd;

	if(arg == NULL)
		return (NULL);
	tmp = arg;
	while (tmp)
	{
		if (ft_strcmp(tmp->arg_pure, "|") == 0)
		{
			size = get_cmdsize(&arg);
			
		}


		tmp = tmp->next;
	}

	return (cmd);
}
