#include "../../inc/minishell.h"

/*
**	@brief		funtion count the lenght array
**
**	@param		arr pointer two dimensional array
**	@return		lenght array
*/
//static int	ms_arrlen(char **arr)
//{
//	int	len;
//
//	len = 0;
//	if (arr == NULL)
//		return (0);
//	while (arr[len])
//		len++;
//	return (len);
//}

/*
**	@brief		function tests for a decimal digit characte 
**
**	@param		string
**	@return		functions return 1 if string contain a only digit
*/
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

static unsigned char	ms_atoi_char(char *str)
{
	char	num;
	int		i;
	int		minus;

	i = 0;
	minus = 1;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
	{	
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i])
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * minus);
}

int	ms_msg(char *argv1, char *str)
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
		exit(255);
	}
	return (0);
}

int	ms_exit(char **argv)
{
	int		len;
	char	num;

	len = ms_arrlen(argv);
	if (len == 1)
		exit(0); // тут нужен предыдущий статус за место нуля
	if (ms_isdigit_str(argv[1]))
		return (ms_msg(argv[1], "numeric argument required"));
	if (len > 2)
		return (ms_msg(NULL, "too many arguments"));
	if (len == 2)
	{
		num = ms_atoi_char(argv[1]);
		exit(num);
	}
	return (0);
}

//int	main(int argc, char **argv)
//{
//	ms_exit(argv);
//	while (1)
//		;
//	return (0);
//}
// gcc ms_exit.c ./../ms_return_error.c ./../../src/libft/libft.a && ./a.out