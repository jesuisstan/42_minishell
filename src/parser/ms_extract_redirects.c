#include "../../inc/minishell.h"

static void	lstadd_back_rdr(t_rdr **rdr_l, t_rdr *new)
{
	t_rdr	*last;

	if (rdr_l && (*rdr_l) && new)
	{
		last = *rdr_l;
		if (last == NULL)
			*rdr_l = new;
		else
		{
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	else if (*rdr_l == NULL)
		*rdr_l = new;
}

static t_rdr	*lstnew_rdr(char *content)
{
	t_rdr	*list;

	list = (t_rdr *)malloc(sizeof(t_rdr));
	if (!list)
		return (NULL);
	list->name = ft_strdup(content);
	list->next = NULL;
	free(content);
	return (list);
}

static int	ft_isredirect(char *str)
{
	if ((ft_strcmp(str, ">") == 0)
		|| (ft_strcmp(str, ">>") == 0)
		|| (ft_strcmp(str, "<") == 0)
		|| (ft_strcmp(str, "<<") == 0))
		return (1);
	return (0);
}

static void	lstremove_node_arg(t_arg **arg)
{
	t_arg	*tmp;

	if(!arg || !(*arg))
		return ;
	tmp = (*arg)->next;
	lstdelone_arg(*arg);
	*arg = tmp;
}

t_rdr	*ms_extract_redirects(t_arg **arg)
{
	t_rdr	*rdr;
	t_arg	*tmp;
//	t_arg	*tmp1;
	char	*content;

	if(!arg || !(*arg))
		return (NULL);
	rdr = NULL;
	if (ft_isredirect((*arg)->arg_pure) == 1)
	{
		content = ft_strjoin((*arg)->arg_pure, (*arg)->next->arg_pure);
		lstadd_back_rdr(&rdr, lstnew_rdr(content));
		*arg = (*arg)->next->next;
		ms_extract_redirects(arg); //todo
	}
	tmp = *arg;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->arg_pure, "|") == 0)
			break;
	//	else if (ft_isredirect(tmp->arg_pure) == 1)
	//{
	//	content = ft_strjoin(tmp->arg_pure, tmp->next->arg_pure);
	//	lstadd_back_rdr(&rdr, lstnew_rdr(content));
	//	lstremove_node_arg(&(tmp));
	//	lstremove_node_arg(&(tmp));
	//	//tmp = tmp->next->next;
	//}
		else if (ft_isredirect(tmp->next->arg_pure) == 1)
		{
			content = ft_strjoin(tmp->next->arg_pure, tmp->next->next->arg_pure);
			lstadd_back_rdr(&rdr, lstnew_rdr(content));
			lstremove_node_arg(&(tmp->next));
			lstremove_node_arg(&(tmp->next));
		}
		else if (tmp->next)
			tmp = tmp->next;
	}
	return (rdr);
}
