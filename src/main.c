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
	while (1)
	{
		ms_parse(g_msh, envp);
		printf("line XXX = %s\n", g_msh->line);
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
