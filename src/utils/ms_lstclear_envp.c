#include "../../inc/minishell.h"

static void	ms_lstdelone_envp(t_envp *envp_l)
{
	if (!envp_l)
		return ;
	free (envp_l->content);
	envp_l->content = NULL;
	free (envp_l->key);
	envp_l->key = NULL;
	free (envp_l->value);
	envp_l->value = NULL;
	free (envp_l);
	envp_l = NULL;
}

void	ms_lstclear_envp(t_envp **envp_l)
{
	t_envp	*tmp;

	if (!envp_l || !*envp_l)
		return ;
	while (envp_l && *envp_l)
	{
		tmp = (*envp_l)->next;
		ms_lstdelone_envp(*envp_l);
		*envp_l = tmp;
	}
}
