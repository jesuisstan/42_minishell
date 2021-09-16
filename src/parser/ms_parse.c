#include "../../inc/minishell.h"

static char	*manage_space(char *line, int *i)
{	
	int		j;
	char	*line_new;
	char	*tail;
	char	*tmp;
	
	j = *i;
	while(line[++(*i)])
		if (!ft_iswhitespace(line[*i]))
			break ;
	tmp = ft_substr(line, 0, j);
	if (line[*i] == '\0')
		line_new = ft_strjoin(tmp, "");
	else
	{
		tail = ft_strdup(&line[*i]);
		line_new = ft_strjoin(tmp, ft_strjoin(" ", tail));
		free (tail);
	}
	*i = j;
	free (tmp);
	free (line);
	return (line_new);
}

static char	*manage_quotes(char *line, int *i, t_msh *msh)
{
	int		j;
	char	*line_new;
	char	*tail;

	j = *i;
	while(line[++(*i)])
	{
		if (line[*i] == '$')
		{
			msh->flag_dollar = 1;
			line = ms_manage_dollar(line, i, msh);
		}
		if (line[*i] == '\"')
			break ;
	}
	line_new = ft_substr(line, 0, j);
	line_new = ft_strjoin(line_new, ft_substr(line, j + 1, *i - j - 1));
	tail = ft_strdup(&line[*i + 1]);
	line_new = ft_strjoin(line_new, tail);
	*i -= 2;
	free (line);
	free (tail);
	return (line_new);
}

static char	*manage_apostrophe(char *line, int *i)
{
	int		j;
	char	*line_new;
	char	*tail;

	j = *i;
	while(line[++(*i)])
		if (line[*i] == '\'')
			break ;
	line_new = ft_substr(line, 0, j);
	line_new = ft_strjoin(line_new, ft_substr(line, j + 1, *i - j - 1));
	tail = ft_strdup(&line[*i + 1]);
	line_new = ft_strjoin(line_new, tail);
	*i -= 2;
	free (line);
	free (tail);
	return (line_new);
}

static char	*read_line_safely(char *line)
{
	int		i;
	char	*final_line;

	line = NULL;
	line = readline("minishell § ");
	if (!line)
		exit (0); //replace 0 to actual last error status
	if (*line)
		add_history(line);
	i = ms_pass_whitespaces(line);
	if (i > 0)
	{
		final_line = ft_strdup(&line[i]);
		free (line);
		return (final_line);
	}
	return (line);
}

void	ms_parse(t_msh *msh, char **envp)
{
	int		i;
	int		j;
	char	*tmp;

	msh->line = read_line_safely(msh->line);
	if (!ms_protoparse(msh->line))
	{
		msh->envp_l = ms_clone_envp(envp);
		//msh->arg = ms_split_line(msh->line);
		i = -1;
		while (msh->line[++i])
		{
			if (ft_iswhitespace(msh->line[i]))
				msh->line = manage_space(msh->line, &i);
			if (msh->line[i] == '$')
				msh->line = ms_manage_dollar(msh->line, &i, msh);
			if (msh->line[i] == '\'')
				msh->line = manage_apostrophe(msh->line, &i);
			if (msh->line[i] == '\"')
				msh->line = manage_quotes(msh->line, &i, msh);
		}

	}

}
