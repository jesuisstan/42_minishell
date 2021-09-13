// gcc main.c ./utils/*.c ./parser/*.c ./libft/libft.a -lreadline -o minishell
// $USER123 'gfgf     "h'
#include "../inc/minishell.h"

t_arguments	*arg;

int	main(int argc, char **argv, char **envp)
{
	int	i;

	arg = ms_malloc_x(sizeof(t_arguments));
	rl_outstream = stderr;
	while (1)
	{
		ms_parse(arg, envp);
		printf("%s\n", arg->line); // todo
		
	}
	return (0);
}
