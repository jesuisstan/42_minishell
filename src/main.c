// gcc main.c ./utils/*.c ./parser/*.c ./libft/libft.a -lreadline -o minishell
// $USER123 'gfgf     "h' !!!!!!!!!!!!!!!!
#include "../inc/minishell.h"

t_msh	*g_msh;

int	main(int argc, char **argv, char **envp)
{
	int		i;
		
	g_msh = ms_malloc_x(sizeof(t_msh));
	rl_outstream = stderr;
	g_msh->envp_l = ms_clone_envp(envp);
	g_msh->last_exit_status = 666666; // todo DELETE!
	while (1)
	{
		g_msh->arg = NULL; // todo чтоб не сегаться при распечатке списка, если вылетело еще на protoparse
		ms_parse(g_msh, g_msh->envp_l);
		while (g_msh->arg) //todo распечатывает связ. список с аргументами line
		{
			printf("arg rare = %s\n", g_msh->arg->arg_rare);
			printf("arg pure = %s\n", g_msh->arg->arg_pure);
			printf("\n");
			g_msh->arg = g_msh->arg->next;
		}
	}
	return (0);
}
