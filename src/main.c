// gcc main.c ./utils/*.c ./parser/*.c ./libft/libft.a -lreadline -o minishell
// $USER123 'gfgf     "h' !!!!!!!!!!!!!!!!
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
	msh->envp_m = ms_envplist_to_array(msh->envp_l);
	while (1)
	{
		ms_parse(msh, msh->envp_l, g_status);
		ms_pipex(msh, msh->cmd_l); // todo SEGA, если НЕ пройден этап протопарсера ВРОДЕ ИСПРАВИЛ
		//while (msh->cmd_l) //todo
		//{
		//	int	k = -1;
		//	while (msh->cmd_l->cmd[++k])
		//		//ft_putstr_fd(msh->cmd_l->cmd[k], 1);
		//		ft_putendl_fd(msh->cmd_l->cmd[k], 1);
		//	printf("--------\n");
		//	msh->cmd_l = msh->cmd_l->next;
		//}
		
		ms_lstclear_arg(&(msh->arg));
		ms_lstclear_cmd(&(msh->cmd_l));
	}
	return (0);
}
