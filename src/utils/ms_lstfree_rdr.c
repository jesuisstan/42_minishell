/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lstfree_rdr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:18 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/19 17:48:40 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	lstdelone_rdr(t_rdr *rdr)
{
	if (!rdr)
		return ;
	free(rdr->name);
	rdr->name = NULL;
	free(rdr);
	rdr = NULL;
}

void	ms_lstfree_rdr(t_rdr **rdr)
{
	t_rdr	*tmp;

	if (!rdr || !*rdr)
		return ;
	while (rdr && *rdr)
	{
		tmp = (*rdr)->next;
		lstdelone_rdr(*rdr);
		*rdr = tmp;
	}
}
