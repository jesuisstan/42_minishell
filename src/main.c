// gcc main.c ./utils/*.c ./parser/*.c ./libft/libft.a -lreadline -o minishell
// $USER123 'gfgf     "h'
#include "../inc/minishell.h"

t_msh	*msh;

int	main(int argc, char **argv, char **envp)
{
	int	i;

	msh = ms_malloc_x(sizeof(t_msh));
	rl_outstream = stderr;
	while (1)
	{
		ms_parse(msh, envp);
		printf("PARSED LINE is: %s\n", msh->line); // todo
		//printf("\n"); // todo
		//while (msh->arg) //todo
		//{
		//	printf("index = %d\n", msh->arg->index);
		//	printf("argument = %s\n", msh->arg->arg_rare);
		//	msh->arg = msh->arg->next;
		//}
		
	}
	return (0);
}
