// gcc main.c ./utils/*.c ./parser/*.c ./libft/libft.a -lreadline -o minishell

#include "../inc/minishell.h"

t_arguments	*arg;

int	main(int argc, char **argv, char **envp)
{
	arg = ms_malloc_x(sizeof(t_arguments));
	ms_parse(arg, envp);
	
	while (arg->envp_l->next)
	{
		printf("%s\n", arg->envp_l->content);
		printf("%s ", arg->envp_l->key);
		printf("%s\n", arg->envp_l->value);
		arg->envp_l = arg->envp_l->next;
	}

	return (0);
}
