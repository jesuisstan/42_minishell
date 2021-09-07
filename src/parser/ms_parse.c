#include "../../inc/minishell.h"

static char	*read_line(char *line)
{
	line = NULL;
	line = readline(line);
	return (line);
}

void	ms_parse(t_arguments *arg, char **envp)
{
	char	*line;
	int i;
	
	arg->envp_l = ms_clone_envp(envp);
	line = read_line(line);
	if (ms_protoparse(line))
		exit (EXIT_FAILURE);

	free (line);
}
