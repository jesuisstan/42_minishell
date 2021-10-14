#include "../../inc/minishell.h"

static char	*handle_char_key(char *line, char *value, int j, int *i)
{
	char	*line_new;
	char	*tmp_one;

	if (!value)
	{
		line_new = ft_strjoin(ft_substr(line, 0, j), ft_strdup(&line[*i]));
		*i = j - 1;
	}
	else
	{
		tmp_one = ft_strjoin(ft_substr(line, 0, j), value);
		line_new = ft_strjoin(tmp_one, ft_strdup(&line[*i]));
		*i = j + ft_strlen(value) - 1;
		free(tmp_one);
	}
	return (line_new);
}

static char	*handle_digital_key(char *line, char *key, int j, int *i)
{
	char	*line_new;
	char	*tmp_one;

	if (key[0] == '0')
	{
		tmp_one = ft_strjoin(ft_substr(line, 0, j),
				ft_strjoin("minishell", &key[1]));
		line_new = ft_strjoin(tmp_one, ft_strdup(&line[*i]));
		*i = j + ft_strlen(key) + ft_strlen("minishell") - 2;
		free(tmp_one);
	}
	else if (ft_strlen(key) > 1)
	{
		tmp_one = ft_strjoin(ft_substr(line, 0, j), &key[1]);
		line_new = ft_strjoin(tmp_one, ft_strdup(&line[*i]));
		*i = j + ft_strlen(key) - 2;
		free(tmp_one);
	}
	else
	{
		line_new = ft_strjoin(ft_substr(line, 0, j), ft_strdup(&line[*i]));
		*i = j - 1;
	}
	free(key);
	return (line_new);
}

static int	if_key(char c)
{
	if (c == '_' || ft_isalnum(c) || c == '*' || c == '!')
		return (1);
	return (0);
}

static char	*handle_question_mark(char *line, int j, int *i)
{
	char	*line_new;
	char	*tmp_one;
	char	*nbr_val;
	char	*tail;

	nbr_val = ft_itoa(g_status.exit);
	tmp_one = ft_strjoin(ft_substr(line, 0, j), nbr_val);
	tail = ft_strdup(&line[*i]);
	line_new = ft_strjoin(tmp_one, tail);
	free(nbr_val);
	free(tmp_one);
	free(tail);
	free(line);
	g_status.exit = 0;
	return (line_new);
}

char	*ms_manage_dollar(char *line, int *i, t_envp *envp_l)
{
	int		j;
	char	*key;
	char	*value;
	char	*line_new;

	j = *i;
	if (ft_strchr("?", line[j + 1]))
	{
		*i += 2;
		return (handle_question_mark(line, j, i));
	}
	while (line[++(*i)])
		if (!if_key(line[*i]))
			break ;
	if (*i == j + 1)
		return (line);
	key = ft_substr(line, j + 1, *i - j - 1);
	if (ft_isdigit(key[0]))
		return (handle_digital_key(line, key, j, i));
	else
		value = ms_find_envp_l(&envp_l, key);
	line_new = handle_char_key(line, value, j, i);
	free(key);
	free(line);
	return (line_new);
}
