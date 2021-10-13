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
