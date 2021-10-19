/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshmelly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:17 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/17 18:58:17 by mshmelly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	free_lst(t_envp	*lst)
{
	free(lst->value);
	free(lst->key);
	free(lst->content);
	free(lst);
}

static void	del_elem(t_envp **head)
{
	t_envp	*for_del;

	for_del = (*head)->next;
	(*head)->next = (*head)->next->next;
	free_lst(for_del);
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
	else if (n >= 0)
	{
		cur = (*head);
		while (--n)
			cur = cur->next;
		del_elem(&(cur));
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
	return (-1);
}

int	ms_unset(t_msh *msh, char **argv)
{
	int	ind_del;
	int	i;

	i = 1;
	if (ms_arrlen(argv) == 1)
		return (0);
	else
	{
		while (argv[i])
		{
			ind_del = ms_find_envp_l_ind(msh->envp_l, argv[i]);
			if (ind_del >= 0)
				del_nth(&(msh->envp_l), ind_del);
			ind_del = -1;
			i++;
		}
	}
	return (0);
}
