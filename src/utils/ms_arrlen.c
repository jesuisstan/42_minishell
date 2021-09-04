#include "../../inc/minishell.h"

/*
**	@brief		funtion count the lenght array
**
**	@param		envp and key
**	@return		the contents of the key in the environment
*/
int	ms_arrlen(char **arr)
{
	int	len;

	len = 0;
	if (arr == NULL)
		return (0);
	while (arr[len])
		len++;
	return (len);
}
