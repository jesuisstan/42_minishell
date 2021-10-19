/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lstfree_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:18 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/19 18:10:44 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	lstdelone_arg(t_arg *arg)
{
	if (!arg)
		return ;
	free(arg->arg_pure);
	arg->arg_pure = NULL;
	free(arg);
}

void	ms_lstfree_arg(t_arg **arg)
{
	t_arg	*tmp;

	if (!arg || !*arg)
		return ;
	while (arg && *arg)
	{
		tmp = (*arg)->next;
		lstdelone_arg(*arg);
		*arg = tmp;
	}
}
