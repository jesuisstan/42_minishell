/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshmelly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:17 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/17 18:58:17 by mshmelly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	swap_action(t_envp **lst)
{
	t_envp	*tmp;

	if ((*lst) || (*lst)->next || (*lst)->next->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		tmp->next = (*lst);
		(*lst) = tmp;
	}
}

static int	sorting(t_envp **lst)
{
	int		flag;
	t_envp	*cur;

	flag = 0;
	if (!(*lst) || !(*lst)->next)
		return (0);
	if (ft_strcmp((*lst)->key, (*lst)->next->key) > 0)
		swap_action(lst);
	cur = (*lst);
	while (cur->next->next)
	{
		if (ft_strcmp(cur->next->key, cur->next->next->key) > 0)
		{
			swap_action(&(cur->next));
			flag++;
		}
		cur = cur->next;
	}
	if (flag)
		sorting(lst);
	return (0);
}

int	not_valid(char *agr)
{
	ft_putstr_fd (MSH, STDERR_FILENO);
	ft_putstr_fd("export`", STDERR_FILENO);
	ft_putstr_fd(agr, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
	return (1);
}

static int	check_export(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '=')
		return (not_valid(arg));
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isdigit(arg[0]) || !ft_isalpha(arg[0]))
			return (not_valid(arg));
		if (!ft_isdigit(arg[i]) && !ft_isalpha(arg[i]))
			return (not_valid(arg));
		i++;
	}
	return (0);
}

int	ms_export(t_msh *msh, char **argv)
{
	char	*key;
	char	*value;

	if (ms_arrlen(argv) == 1)
		return (sorting(&msh->envp_l) + print_env_l(msh->envp_l));
	else
	{
		while (*++argv)
		{
			if (check_export(*argv))
				return (1);
			key = get_key(*argv);
			value = get_value(*argv);
			if (is_key_exist(&msh->envp_l, key))
				ms_find_envp_l_and_replace_val(&msh->envp_l, key, value);
			else
				lstadd_back_envp(&msh->envp_l, lstnew_envp(*argv));
			free(key);
			if (value)
				free(value);
		}
	}
	return (0);
}
