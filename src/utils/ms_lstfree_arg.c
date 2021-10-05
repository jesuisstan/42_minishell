#include "../../inc/minishell.h"

static void	ms_lstdelone_arg(t_arg *arg)
{
	if (!arg)
		return ;
	free(arg->arg_rare);
	arg->arg_rare = NULL;
	free(arg->arg_pure);
	arg->arg_pure = NULL;
	free(arg);
	arg = NULL;
}

void	ms_lstfree_arg(t_arg **arg)
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
