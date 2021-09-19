#include "../../inc/minishell.h"

static char	*manage_space(char *line, int *i)
{	
	int		j;
	char	*line_new;
	char	*tail;
	char	*tmp;

	j = *i;
	while (line[++(*i)])
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

static char	*manage_quotes(char *line, int *i, t_msh *g_msh)
{
	int		j;
	char	*line_new;
	char	*tail;
	char	*tmp;

	j = *i;
	while (line[++(*i)])
	{
		//if (line[*i] == '$')
		//{
		//	g_msh->flag_dollar = 1;
		//	line = ms_manage_dollar(line, i, g_msh);
		//}
		if (line[*i] == '\"')
			break ;
	}
	tmp = ft_strjoin(ft_substr(line, 0, j),
			ft_substr(line, j + 1, *i - j - 1));
	tail = ft_strdup(&line[*i + 1]);
	line_new = ft_strjoin(tmp, tail);
	*i -= 2;
	free (line);
	free (tmp);
	free (tail);
	return (line_new);
}

static char	*manage_apostrophe(char *line, int *i)
{
	int		j;
	char	*line_new;
	char	*tail;
	char	*tmp_one;
	char	*tmp_two;

	j = *i;
	while (line[++(*i)])
		if (line[*i] == '\'')
			break ;
	tmp_one = ft_substr(line, 0, j);
	tmp_two = ft_strjoin(tmp_one, ft_substr(line, j + 1, *i - j - 1));
	tail = ft_strdup(&line[*i + 1]);
	line_new = ft_strjoin(tmp_two, tail);
	*i -= 2;
	free (line);
	free (tmp_one);
	free (tmp_two);
	free (tail);
	return (line_new);
}

char	*ms_purify_argument(char *arg, t_msh *g_msh)
{
	int		i;
	char	*arg_pure;

	i = -1;
	while (arg[++i])
	{
		//if (arg[i] == '$')
		//{
		//	arg = ms_manage_dollar(arg, &i, g_msh);
		//	arg_pure = arg;
		//}
		if (arg[i] == '\'')
		{
			arg = manage_apostrophe(arg, &i);
			arg_pure = arg;
		}
		else if (arg[i] == '\"')
		{
			arg = manage_quotes(arg, &i, g_msh);
			arg_pure = arg;
		}
		else
			arg_pure = arg;
	}
	return (arg_pure);
}
