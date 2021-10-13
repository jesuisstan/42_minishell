// case $? (результат 0): echo $? | grep 1 | echo $? | cat -e
#include "./../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_msh	*msh;

	(void)argc;
	(void)argv;
	rl_outstream = stderr;
	g_status.exit = 0;
	msh = ms_malloc_x(sizeof(t_msh));
	msh->arg = NULL;
	msh->cmd_l = NULL;
	msh->envp_l = ms_clone_envp(envp);
	ms_shlvl_up(msh);
	msh->envp_m = ms_envplist_to_array(msh->envp_l);
	while (1)
	{
		ms_signals_interactive_shell();
		ms_parse(msh, msh->envp_l);
		ms_signals_non_interactive_shell();
		ms_pipex(msh, msh->cmd_l);
		ms_signals_interactive_shell();
		//ms_lstfree_arg(&(msh->arg));
		//ms_lstfree_cmd(&(msh->cmd_l));
	}
	return (0);
}
