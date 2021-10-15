#include "../../inc/minishell.h"

static int	ms_isdigit_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ms_msg(t_msh *msh, char *argv1, char *str)
{
	ft_putstr_fd(MSH, STDERR_FILENO);
	ft_putstr_fd("exit: ", STDERR_FILENO);
	if (argv1 != NULL)
	{
		ft_putstr_fd(argv1, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (argv1 != NULL)
	{
		ms_shlvl_down(msh);
		g_status.exit = 255;
		exit(255);
	}
	else
	{
		return (1);
	}
	return (0);
}

static unsigned char	ms_atoi_char(t_msh *msh, char *str)
{
	int				negative;
	int				i;
	long long int	convert;

	negative = 1;
	i = 0;
	convert = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -negative;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		convert = convert * 10 + (str[i++] - '0');
		if (i > 20)
			ms_msg(msh, str, "numeric argument required");
	}
	if ((convert - 3 >= 9223372036854775807 && negative == -1) \
		|| (convert - 1 >= 9223372036854775807 && negative == 1))
		ms_msg(msh, str, "numeric argument required");
	return (convert * negative);
}

int	ms_exit(t_msh *msh, char **argv)
{
	int		len;

	len = ms_arrlen(argv);
	if (len == 1)
	{
		ms_shlvl_down(msh);
		exit(g_status.exit);
	}
	if (ms_isdigit_str(argv[1]))
		return (ms_msg(msh, argv[1], "numeric argument required"));
	if (len > 2)
		return (ms_msg(msh, NULL, "too many arguments"));
	if (len == 2)
	{
		g_status.exit = ms_atoi_char(msh, argv[1]);
		ms_shlvl_down(msh);
		exit(g_status.exit);
	}
	return (0);
}
