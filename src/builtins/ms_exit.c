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
	else
		exit (1);
	return (0);
}

static unsigned char	ms_atoi_char(char *str)
{
	int			negative;
	int			i;
	uint64_t	convert;

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
		if(i > 20)
			ms_msg(str, "numeric argument required");
	}
	if (convert > 9223372036854775807)
		ms_msg(str, "numeric argument required");
	return (convert * negative);
}

int	ms_exit(char **argv)
{
	int		len;
	char	num;

	len = ms_arrlen(argv);
	if (len == 1)
		exit(g_status); // тут нужен предыдущий статус за место нуля
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
