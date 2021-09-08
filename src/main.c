// gcc main.c ./utils/*.c ./parser/*.c ./libft/libft.a -lreadline -o minishell

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
		
	}
	return (0);
}
