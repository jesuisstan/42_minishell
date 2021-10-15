#include "../../inc/minishell.h"

static void	free_lst(t_envp	*lst)
{
	free(lst->value);
	free(lst->key);
	free(lst->content);
}

static void	del_elem(t_envp **head)
{
	t_envp	*prev;

	prev = NULL;
	prev = (*head);
	(*head) = (*head)->next;
	free_lst(prev);
}

static void	del_nth(t_envp **head, int n)
{
	t_envp	*prev;
	t_envp	*cur;

	prev = NULL;
	cur = NULL;
	if (!(*head) || !head)
		return ;
	if (n == 0)
	{
		prev = (*head);
		(*head) = (*head)->next;
		free_lst(prev);
	}
	else
	{
		cur = (*head);
		while (--n)
			cur = cur->next;
		del_elem(&(cur->next));
	}
}

int	ms_find_envp_l_ind(t_envp *lst, char *key)
{
	int		index;
	t_envp	*tmp;

	index = 0;
	tmp = lst;
	if (tmp && key)
	{
		while (tmp)
		{
			if (!ft_strcmp(tmp->key, key))
				return (index);
			index++;
			tmp = tmp->next;
		}
	}
	return (0);
}

int	ms_unset(t_msh *msh, char **argv)
{
	int	ind_del;
	int	i;

	i = 0;
	if (ms_arrlen(argv) == 1)
		return (0);
	else
	{
		while (argv[i++])
		{
			ind_del = ms_find_envp_l_ind(msh->envp_l, argv[i]);
			del_nth(&(msh->envp_l), ind_del);
		}
	}
	return (0);
}
