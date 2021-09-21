// gcc main.c ./utils/*.c ./parser/*.c ./libft/libft.a -lreadline -o minishell
// $USER123 'gfgf     "h' !!!!!!!!!!!!!!!!
#include "../inc/minishell.h"

t_msh	*g_msh;

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**res;
	
	g_msh = ms_malloc_x(sizeof(t_msh));
	rl_outstream = stderr;
	g_msh->envp_l = ms_clone_envp(envp);
	g_msh->last_exit_status = 666666; // todo DELETE!
	while (1)
	{
		ms_parse(g_msh, g_msh->envp_l);
		
		t_arg *arg_cp = g_msh->arg; //todo
		while (arg_cp) //todo распечатывает связ. список с аргументами line
		{
			printf("arg rare = %s\n", arg_cp->arg_rare);
			printf("arg pure = %s\n", arg_cp->arg_pure);
			printf("\n");
			arg_cp = arg_cp->next;
		}
		printf("HERE EXEC CMDS IN PROGRESS\n"); //todo
		ms_lstclear_arg(&(g_msh->arg)); // очищаю список с аргументами. Обязательно!
		ms_lstclear_arg(&arg_cp); // очищаю список с аргументами. Обязательно!
	}
	return (0);
}
