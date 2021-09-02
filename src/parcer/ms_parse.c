
#include "../../inc/minishell.h"

static char	*read_line(char *line)
{
	line = NULL;
	get_next_line(STDIN_FILENO, &line);
	return (line);
}

void	ms_parse(t_arguments *arguments)
{
	char *line;
	
	line = read_line(line);
	printf("%s\n", line);
}

