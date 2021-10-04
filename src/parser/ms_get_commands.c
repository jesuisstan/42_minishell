#include "../../inc/minishell.h"

char **make_cmdarray(char *str_cmd, char* str_flags) // todo не нужна
{
	int		size;
	int		i;
	char	**cmd_arr;

	if(!str_cmd || !str_flags)
		return (NULL);
	if (ft_strcmp(str_flags, "") == 0)
	{
		cmd_arr = (char **)malloc(sizeof(char *) * 2);
		if (!cmd_arr)
			return (NULL);
		cmd_arr[0] = str_cmd;
		cmd_arr[1] = NULL;
	}
	else
	{
		cmd_arr = (char **)malloc(sizeof(char *) * 3);
		if (!cmd_arr)
			return (NULL);
		cmd_arr[0] = str_cmd;
		cmd_arr[1] = str_flags;
		cmd_arr[2] = NULL;
	}
	return (cmd_arr);
}

t_cmd	*ms_lstnew_cmd(t_arg *arg, int size)
{
	t_cmd	*cmd_l;

	cmd_l = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd_l)
		return (NULL);
	cmd_l->cmd = ms_arglist_to_array(arg, size); // todo arg - кусок листа t_arg до пайпа
	cmd_l->next = NULL;
	return (cmd_l);
}

static void	lstadd_back_cmd(t_cmd **lst, t_cmd *new_node)
{
	t_cmd	*last;

	if (lst && (*lst) && new_node)
	{
		last = *lst;
		if (last == NULL)
			*lst = new_node;
		else
		{
			while (last->next)
				last = last->next;
			last->next = new_node;
		}
	}
	else if (*lst == NULL)
		*lst = new_node;
}

static size_t	get_cmds_amount(t_arg *arg)
{
	size_t	i;
	t_arg	*tmp;

	if (!arg)
		return (-1);
	tmp = arg;
	i = 1;
	while (tmp)
	{
		if (ft_strcmp(tmp->arg_pure, "|") == 0)
		{
			tmp = tmp->next;
			i++;
		}
		tmp = tmp->next;
	}
	return (i);
}

static size_t	get_cmd_size(t_arg *arg)
{
	size_t	i;
	
	if (!arg)
		return (-1);
	i = 0;
	while (arg)
	{
		arg = arg->next;
		i++;
		if (ft_strcmp(arg->arg_pure, "|") == 0)
			break;
	}
	return (i);
}

t_cmd	*ms_get_commands(t_arg *arg)
{
	int		i;
	int		cmd_size;
	t_arg	*head;
	t_cmd 	*cmd_l;

	if(arg == NULL)
		return (NULL);
	head = arg;
	cmd_l = NULL;
	cmd_size = 1;
	while (arg != NULL)
	{
		if (ft_strcmp(arg->arg_pure, "|") == 0)
		{
			cmd_size = get_cmd_size(head);
			lstadd_back_cmd(&cmd_l, ms_lstnew_cmd(head, cmd_size));
			head = arg->next;
			cmd_size = 1;
		}
		arg = arg->next;
		cmd_size++;
		if (arg == NULL)
			lstadd_back_cmd(&cmd_l, ms_lstnew_cmd(head, cmd_size));
	}
	return (cmd_l);
}

