#include "../../inc/minishell.h"

static void	ms_lstdelone_arg(t_arg *arg)
{
	if (!arg)
		return ;
	free (arg->arg_pure);
	free (arg->arg_rare);
	free (arg);
}

void	ms_lstclear_arg(t_arg **arg)
{
	t_arg	*tmp;

	if (!arg || !*arg)
		return ;
	while (arg && *arg)
	{
		tmp = (*arg)->next;
		ms_lstdelone_arg(*arg);
		*arg = tmp;
	}
}
