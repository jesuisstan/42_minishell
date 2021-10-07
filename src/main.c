// gcc main.c ./utils/*.c ./parser/*.c ./libft/libft.a -lreadline -o minishell
// $USER123 'gfgf     "h' !!!!!!!!!!!!!!!!
// echo test > ls >> ls >> ls
#include "./../inc/minishell.h"

int g_status;

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
	msh->envp_m = ms_envplist_to_array(msh->envp_l);
	while (1)
	{
		ms_parse(msh, msh->envp_l, g_status);
		ms_pipex(msh, msh->cmd_l);

// печать команд и списков с редиректами:
//t_cmd *tmp_cmd = msh->cmd_l;
//while (tmp_cmd) //todo
//{
//	int	k = -1;
//	ft_putstr_fd("cmd:\n", 1);
//	while (tmp_cmd->cmd[++k])
//	{
//		//ft_putstr_fd(msh->cmd_l->cmd[k], 1);
//		ft_putendl_fd(tmp_cmd->cmd[k], 1);
//	}
//	ft_putstr_fd("redirects:\n", 1);
//	t_rdr *tmp_r = tmp_cmd->rdr;	
//	while (tmp_r)
//	{
//		printf("%s\n", tmp_r->name);
//		tmp_r = tmp_r->next;
//	}
//	printf("--------\n");
//	tmp_cmd = tmp_cmd->next;
//}

		ms_lstfree_arg(&(msh->arg));
		ms_lstfree_cmd(&(msh->cmd_l));
	}
	return (0);
}
