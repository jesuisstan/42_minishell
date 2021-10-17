// case $? (результат д.б. 0): echo $? | grep 1 | echo $? | cat -e

// CASE: (из папки msh, где лежат CMakeLists и Makefile)
// действие 1: ls -la > f1
// действие 2: < f1 cat | grep ake | cat -e  >f2
// в результате в файле f2 должны оказаться 2 строчки:
//      -rw-r--r--   1 acaren  4221     1423 Oct 15 21:15 CMakeLists.txt$
//      -rw-------   1 acaren  4221     1022 Oct 13 13:02 Makefile$
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
	while (1)
	{
		ms_signals_interactive_shell();
		ms_parse(msh, msh->envp_l);

//		t_cmd *tmp_cmd = msh->cmd_l;
//while (tmp_cmd) //todo
//{
//	int	k = -1;
//	ft_putstr_fd("cmd:\n", 1);
//	while (tmp_cmd->cmd[++k])
//	{
//		ft_putstr_fd(tmp_cmd->cmd[k], 1);
//		ft_putstr_fd("±", 1);
//		//ft_putendl_fd(tmp_cmd->cmd[k], 1);
//	}
//	ft_putstr_fd("\nredirects:\n", 1);
//	t_rdr *tmp_r = tmp_cmd->rdr;	
//	while (tmp_r)
//	{
//		printf("%s\n", tmp_r->name);
//		tmp_r = tmp_r->next;
//	}
//	printf("--------\n");
//	tmp_cmd = tmp_cmd->next;
//}

		ms_signals_non_interactive_shell();
		if (msh->cmd_l)
			ms_pipex(msh, msh->cmd_l, ms_lstsize(msh->cmd_l));
		ms_signals_interactive_shell();
		if (msh->cmd_l)
			ms_lstfree_cmd(&(msh->cmd_l));
	}
	return (0);
}
