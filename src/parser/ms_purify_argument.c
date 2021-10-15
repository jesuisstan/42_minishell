#include "../../inc/minishell.h"

static char	*manage_quotes(char *line, int *i, t_msh *msh)
{
	int		j;
	char	*line_new;
	char	*tail;
	char	*tmp_one;
	char	*tmp_two;
	char	*tmp_three;

	(void)msh;
	j = *i;
	while (line[++(*i)])
		if (line[*i] == '\"')
			break ;
	tmp_one = ft_substr(line, 0, j);
	tmp_two = ft_substr(line, j + 1, *i - j - 1);
	tmp_three = ft_strjoin(tmp_one, tmp_two);;
	tail = ft_strdup(&line[*i + 1]);
	line_new = ft_strjoin(tmp_three, tail);
	*i -= 2;
	free(tmp_one);
	free(tmp_two);
	free(tmp_three);
	free(tail);
	free(line);
	return (line_new);
}

static char	*manage_apostrophe(char *line, int *i)
{
	int		j;
	char	*line_new;
	char	*tail;
	char	*tmp_one;
	char	*tmp_two;
	char	*tmp_three;

	j = *i;
	while (line[++(*i)])
		if (line[*i] == '\'')
			break ;
	tmp_one = ft_substr(line, 0, j);
	tmp_two = ft_substr(line, j + 1, *i - j - 1);
	tmp_three = ft_strjoin(tmp_one, tmp_two);
	tail = ft_strdup(&line[*i + 1]);
	line_new = ft_strjoin(tmp_three, tail);
	*i -= 2;
	free(tmp_one);
	free(tmp_two);
	free(tmp_three);
	free(tail);
	free(line);
	return (line_new);
}

char	*ms_purify_argument(char *arg, t_msh *msh)
{
	int		i;
	char	*arg_pure;

	arg += ms_pass_whitespaces(arg);
	arg = ms_clear_endwhitespaces(arg);
	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '\'')
		{
			arg = manage_apostrophe(arg, &i);
			arg_pure = arg;
		}
		else if (arg[i] == '\"')
		{
			arg = manage_quotes(arg, &i, msh);
			arg_pure = arg;
		}
		else
			arg_pure = arg;
	}
	return (arg_pure);
}
