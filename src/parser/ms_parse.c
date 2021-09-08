#include "../../inc/minishell.h"

static char	*read_line(char *line)
{
	line = NULL;
	line = readline("minishell > ");
	if (!line)
		exit (0); //replace 0 to actual last error status
	if (*line)
		add_history(line);
	return (line);
}

int	ms_parse(t_arguments *arg, char **envp)
{
	char	*line;
	int i;
	
	arg->envp_l = ms_clone_envp(envp);
	line = read_line(line);
	ms_protoparse(line);

	free (line);
	return (0);
}
