#include "../../inc/minishell.h"

static int	get_cmd_size(t_arg *arg)
{
	int		i;
	t_arg	*tmp;

	if (!arg)
		return (0);
	tmp = arg;
	i = 0;
	if (tmp->flag_isredirect == 0)
		i = 1;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->arg_pure, "|") == 0)
		{
			i = 0;
			break ;
		}
		tmp = tmp->next;
		if (ft_strcmp(tmp->arg_pure, "|") == 0)
			break ;
		if (tmp->flag_isredirect == 0)
			i++;
	}
	return (i);
}

static t_cmd	*lstnew_cmd(t_arg *arg)
{
	t_cmd	*cmd_l;
	int		size;

	cmd_l = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd_l || !arg)
		return (NULL);
	cmd_l->rdr = NULL;
	cmd_l->rdr = ms_extract_redirects(&arg);
	size = get_cmd_size(arg);
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

t_cmd	*ms_get_commands(t_msh *msh)
{
	t_arg	*head;
	t_arg	*tmp;

	if (msh->arg == NULL)
		return (NULL);
	tmp = msh->arg;
	head = tmp;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->arg_pure, "|") == 0)
		{
			lstadd_back_cmd(&msh->cmd_l, lstnew_cmd(head));
			head = tmp->next;
		}
		tmp = tmp->next;
		if (tmp == NULL)
			lstadd_back_cmd(&msh->cmd_l, lstnew_cmd(head));
	}
	return (msh->cmd_l);
}
