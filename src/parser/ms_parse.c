#include "../../inc/minishell.h"

static char	*replace_dollars(char *line, t_envp *envp_l, t_msh *msh)
{
	int		i;
	int		flag_quote;

	if (!line)
		return (NULL);
	flag_quote = 0;
	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == '$')
			line = ms_manage_dollar(line, &i, envp_l, msh);
		else if (line[i] == '\"' && flag_quote == 0)
			flag_quote = 1;
		else if (line[i] == '\"' && flag_quote == 1)
			flag_quote = 0;
		else if (line[i] == '\'' && flag_quote == 0)
		{
			++i;
			while (line[i] != '\'' && line[i])
				i++;
		}
	}
	return (line);
}

static char	*read_line_safely(char *line, int g_status, t_msh **msh)
{
	int		i;

	line = NULL;
	line = readline("minishell § ");
	if (g_status == 130)
	{
		(*msh)->prev_status = 1;
		g_status = 0;
	}
	if (!line)
		exit(0); // todo replace 0 to actual last error status
	if (*line)
		add_history(line);
	return (line);
}

void	ms_parse(t_msh *msh, t_envp *envp_l, int g_status)
{
	msh->line = read_line_safely(msh->line, g_status, &msh);
	msh->line = ms_clear_endwhitespaces(msh->line);
	if (!ms_protoparse(msh->line))
	{
		msh->line = replace_dollars(msh->line, envp_l, msh);
		msh->arg = ms_split_line(msh);
		msh->cmd_l = ms_get_commands(msh);
	}
	free(msh->line);
	msh->line = NULL;
}
