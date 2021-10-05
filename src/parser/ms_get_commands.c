#include "../../inc/minishell.h"

t_cmd	*ms_lstnew_cmd(t_arg *arg, int size)
{
	t_cmd	*cmd_l;

	cmd_l = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd_l)
		return (NULL);
	cmd_l->cmd = ms_arglist_to_array(arg, size);
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

t_cmd	*ms_get_commands(t_msh *msh)
{
	int		i;
	int		cmd_size;
	t_arg	*head;

	if(msh->arg == NULL)
		return (NULL);
	head = msh->arg;
	cmd_size = 1;
	while (msh->arg != NULL)
	{
		if (ft_strcmp(msh->arg->arg_pure, "|") == 0)
		{
			cmd_size = get_cmd_size(head);
			lstadd_back_cmd(&msh->cmd_l, ms_lstnew_cmd(head, cmd_size));
			head = msh->arg->next;
			cmd_size = 1;
		}
		msh->arg = msh->arg->next;
		cmd_size++;
		if (msh->arg == NULL)
			lstadd_back_cmd(&msh->cmd_l, ms_lstnew_cmd(head, cmd_size));
	}
	ms_lstfree_arg(&head);
	return (msh->cmd_l);
}
