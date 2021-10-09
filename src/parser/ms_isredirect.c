#include "../../inc/minishell.h"

int	ms_isredirect(char *str)
{
	if ((ft_strcmp(str, ">") == 0)
		|| (ft_strcmp(str, ">>") == 0)
		|| (ft_strcmp(str, "<") == 0)
		|| (ft_strcmp(str, "<<") == 0))
		return (1);
	return (0);
}
