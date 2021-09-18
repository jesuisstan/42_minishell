#include "../../inc/minishell.h"

int	ft_iswhitespace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		   || c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	ms_pass_whitespaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
		   || line[i] == '\v' || line[i] == '\r' || line[i] == '\f')
		i++;
	return (i);
}
