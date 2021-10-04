#include "../../inc/minishell.h"

static t_arg	*ms_split_line(char *line, t_msh *msh)
{
	int		i;
	t_arg	*arg;
	
	arg = NULL;
	ms_cut_arguments(line, &arg, msh);
	return (arg);
}

static char	*clear_endwhitespaces(char *line)
{
	char	*line_new;
	int		i;
	int		end;

	i = -1;
	while (line[++i])
	{
		if (ft_strchr(" \t", line[i]))
		{
			end = i;
			i += ms_pass_whitespaces(&line[i]);
			if (line[i + 1] == '\0' && !ft_isprint(line[i]))
			{
				line_new = ft_substr(line, 0, end);
				free(line);
				line = NULL;
				return (line_new);
			}
		}
	}
	return (line);
}

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

static char	*read_line_safely(char *line)
{
	int		i;

	line = NULL;
	line = readline("minishell § ");
	if (!line)
		exit(0); // todo replace 0 to actual last error status
	if (*line)
		add_history(line);
	return (line);
}

void	ms_parse(t_msh *msh, t_envp *envp_l)
{
	msh->line = read_line_safely(msh->line);
	msh->line = clear_endwhitespaces(msh->line);
	if (!ms_protoparse(msh->line))
	{
		msh->line = replace_dollars(msh->line, envp_l, msh);
		msh->arg = ms_split_line(msh->line, msh);
		msh->cmd_l = ms_get_commands(msh->arg);
	}
	free(msh->line);
	msh->line = NULL;
}
