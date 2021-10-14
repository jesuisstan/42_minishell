#include "../../inc/minishell.h"

static void	ms_lstdelone_cmd(t_cmd *cmd_l)
{
	if (!cmd_l)
		return ;
	ft_free_array(&(cmd_l->cmd));
	ms_lstfree_rdr(&(cmd_l->rdr));
	free(cmd_l);
	cmd_l = NULL;
}

void	ms_lstfree_cmd(t_cmd **cmd_l)
{
	t_cmd	*tmp;

	if (!cmd_l || !*cmd_l)
		return ;
	while (cmd_l && *cmd_l)
	{
		tmp = (*cmd_l)->next;
		ms_lstdelone_cmd(*cmd_l);
		*cmd_l = tmp;
	}
}
