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

static int	manage_front_redirect(t_arg **arg, t_rdr **rdr)
{
	char	*content;

	content = NULL;
	while (*arg)
	{
		if (ms_isredirect((*arg)->arg_pure) == 1)
		{
			content = ft_strjoin((*arg)->arg_pure, (*arg)->next->arg_pure);
			lstadd_back_rdr(rdr, lstnew_rdr(content));
			if (!(*arg)->next->next)
			{
				return (1);
			}
			*arg = (*arg)->next->next;
		}
		if (ms_isredirect((*arg)->arg_pure) == 0)
			break ;
	}
	return (0);
}

t_rdr	*ms_extract_redirects(t_arg **arg)
{
	t_rdr	*rdr;
	t_arg	*tmp;
	char	*str;

	if (!arg || !(*arg))
		return (NULL);
	rdr = NULL;
	str = NULL;
	if (manage_front_redirect(arg, &rdr) == 1)
		return (rdr);
	tmp = *arg;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->arg_pure, "|") == 0)
			break ;
		else if (ms_isredirect(tmp->next->arg_pure) == 1)
		{
			str = ft_strjoin(tmp->next->arg_pure, tmp->next->next->arg_pure);
			lstadd_back_rdr(&rdr, lstnew_rdr(str));
			tmp = tmp->next->next;
		}
		else if (tmp->next)
			tmp = tmp->next;
	}
	return (rdr);
}
