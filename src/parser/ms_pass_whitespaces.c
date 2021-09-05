#include "../../inc/minishell.h"

int	ms_pass_whitespaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
		   || line[i] == '\v' || line[i] == '\r' || line[i] == '\f')
		i++;
	return (i);
}
