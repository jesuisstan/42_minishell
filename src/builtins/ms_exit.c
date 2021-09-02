#include "../../inc/minishell.h"

/*
**	@brief		funtion count the lenght array
**
**	@param		arr pointer two dimensional array
**	@return		lenght array
*/
static int	ms_arrlen(char **arr)
{
	int	len;

	len = 0;
	if (arr == NULL)
		return(0);
	while (arr[len])
		len++;
	return (len);
}

/*
**	@brief		function tests for a decimal digit characte 
**
**	@param		string
**	@return		functions return 1 if string contain a only digit
*/
static int ms_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int		ms_exit(char **argv)
{
	int		len;
	char	num;
	
	len = ms_arrlen(argv);
	if (len == 1)
		exit(0);
	if (ms_isdigit_str(argv[1]))
		return(ms_return_nbr(num, "numeric argument required"));
	return (0);
}

int main(int argc, char **argv)
{
	ms_exit(argv);
	return (0);
}