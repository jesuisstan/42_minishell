#include "../../inc/minishell.h"

int	ms_pwd(void)
{
	char	*pwd;
	int		i;

	pwd = ms_malloc_x(sizeof(pwd) * 2048);
	i = -1;
	while (++i < 2048)
		pwd[i] = 0;
	if (getcwd(pwd, 2048))
	{
		ft_putendl_fd(pwd, STDOUT_FILENO);
		free(pwd);
		return (1);
	}
	else
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
	}
	return (0);
}

int	main(int agrc, char *argv[])
{
	ms_pwd();
	return (0);
}

//gcc ms_pwd.c ./../../src/utils/ms_malloc_x.c ./../../src/libft/libft.a && ./a.out