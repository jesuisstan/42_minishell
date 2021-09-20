// gcc main.c ./utils/*.c ./parser/*.c ./libft/libft.a -lreadline -o minishell
// $USER123 'gfgf     "h' !!!!!!!!!!!!!!!!
#include "../inc/minishell.h"

t_msh	*g_msh;
int		i;
char	**res;

int	main(int argc, char **argv, char **envp)
{
	g_msh = ms_malloc_x(sizeof(t_msh));
	rl_outstream = stderr;
	while (1)
	{
		ms_parse(g_msh, envp);
		//printf("line XXX = %s\n", g_msh->line);
		//while (g_msh->arg) //todo распечатывает связ. список с аргументами line
		//{
		//	printf("arg rare = %s\n", g_msh->arg->arg_rare);
		//	printf("arg pure = %s\n", g_msh->arg->arg_pure);
		//	printf("\n");
		//	g_msh->arg = g_msh->arg->next;
		//}
		while (g_msh->envp_l)
		{
			printf("%s\n", g_msh->envp_l->content);
			g_msh->envp_l = g_msh->envp_l->next;
		}
		printf("\nSPACE\n");
		res = ms_envplist_to_array(res, &(g_msh->envp_l));
		i = -1;
		while (res[++i])
		{
			ft_putstr_fd(res[i], STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
	}
	return (0);
}
