#include "./../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_msh	*msh;

	(void)argc;
	(void)argv;
	rl_outstream = stderr;
	g_status = 0;
	msh = ms_malloc_x(sizeof(t_msh));
	msh->arg = NULL;
	msh->cmd_l = NULL;
	msh->envp_l = ms_clone_envp(envp);
	ms_shlvl_up(msh);
	while (1)
	{
		ms_signals_interactive_shell();
		ms_parse(msh, msh->envp_l);
		ms_signals_non_interactive_shell();
		if (msh->cmd_l)
			ms_pipex(msh, msh->cmd_l, ms_lstsize(msh->cmd_l));
		ms_signals_interactive_shell();
		if (msh->cmd_l)
			ms_lstfree_cmd(&(msh->cmd_l));
	}
	return (0);
}
