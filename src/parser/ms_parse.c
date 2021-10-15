#include "../../inc/minishell.h"

static char	*replace_dollars(char *line, t_envp *envp_l)
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
			line = ms_manage_dollar(line, &i, envp_l);
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

static char	*read_line_safely(char *line)
{
	line = NULL;
	line = readline("minishell § ");
	if (!line)
		exit(g_status.exit);
	if (*line)
		add_history(line);
	return (line);
}

void	ms_parse(t_msh *msh, t_envp *envp_l)
{
	msh->line = read_line_safely(msh->line);
	msh->line = ms_clear_endwhitespaces(msh->line);
	if (!ms_protoparse(msh->line))
	{
		msh->line = replace_dollars(msh->line, envp_l);
		msh->arg = ms_split_line(msh);
		//while (msh->arg) //todo распечатывает связ. список с аргументами line
		//{
		//	printf("arg rare = %s\n", msh->arg->arg_rare);
		//	printf("arg pure = %s\n", msh->arg->arg_pure);
		//	printf("\n");
		//	msh->arg = msh->arg->next;
		//}
		msh->cmd_l = ms_get_commands(msh);
	}
	ms_lstfree_arg(&(msh->arg));
	free(msh->line);
}
