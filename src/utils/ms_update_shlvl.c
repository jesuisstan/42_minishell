#include "../../inc/minishell.h"

void	ms_update_shlvl(t_msh *msh)
{
	char	*shlvl_current;
	char	*shlvl_new;

	shlvl_current = ms_find_envp_l(&(msh->envp_l), "SHLVL");
	shlvl_new = ft_itoa((ft_atoi(shlvl_current)) + 1);
	ms_find_envp_l_and_replace_val(&(msh->envp_l), "SHLVL", shlvl_new);
	free(shlvl_current);
	shlvl_current = NULL;
	free(shlvl_new);
	shlvl_new = NULL;
}
