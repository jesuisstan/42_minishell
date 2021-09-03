#include "../../inc/minishell.h"

int	ms_echo(char **arr)
{
	int	opt_n;
	int	i;

	opt_n = 1;
	i = 1;
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], "-n") && i == 1)
		{
			opt_n = 0;
			i++;
		}
		ft_putstr_fd(arr[i], STDOUT_FILENO);
		i++;
		if (arr[i] == NULL)
			break ;
		else
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (opt_n == 1)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}

int	main(int argc, char **argv)
{
	ms_echo(argv);
	//while (1)
	//	;
	return (0);
}
