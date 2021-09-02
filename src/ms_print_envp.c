// gcc *.c ./libft/libft.a -o minishell

#include "../inc/minishell.h"

int	ms_print_envp(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		ft_putstr_fd(envp[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	return (0);
}
