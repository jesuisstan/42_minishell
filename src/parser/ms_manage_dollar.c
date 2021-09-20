#include "../../inc/minishell.h"

static char	*handle_char_key(char *line, char *value, int j, int *i)
{
	char	*line_new;
	char	*tmp_one;

	if (!value)
	{
		tmp_one = ft_strjoin(ft_substr(line, 0, j), "");
		line_new = ft_strjoin(tmp_one, ft_strdup(&line[*i]));
		*i = j - 1;
	}
	else
	{
		tmp_one = ft_strjoin(ft_substr(line, 0, j), value);
		line_new = ft_strjoin(tmp_one, ft_strdup(&line[*i]));
		*i = j + ft_strlen(value) - 1;
		free (value);
	}
	free (tmp_one);
	return (line_new);
}

static char	*handle_digital_key(char *line, char *key, int	j, int *i)
{
	char	*line_new;
	char	*tmp_one;

	if (key[0] == '0')
	{
		tmp_one = ft_strjoin(ft_substr(line, 0, j), ft_strjoin("minishell", &key[1]));
		line_new = ft_strjoin(tmp_one, ft_strdup(&line[*i]));
		*i = j + ft_strlen(key) + ft_strlen("minishell") - 2;
		free (tmp_one);
	}
	else if (ft_strlen(key) > 1)
	{
		tmp_one = ft_strjoin(ft_substr(line, 0, j), &key[1]);
		line_new = ft_strjoin(tmp_one, ft_strdup(&line[*i]));
		*i = j + ft_strlen(key) - 2;
		free (tmp_one);
	}
	else
	{
		line_new = ft_strjoin(ft_substr(line, 0, j), ft_strdup(&line[*i]));
		*i = j - 1;
	}
	free (key);
	return (line_new);
}

static int	if_key(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

char	*ms_manage_dollar(char *line, int *i, char **envp)
{
	int		j;
	char	*key;
	char	*value;
	char	*line_new;

	j = *i;
	while(line[++(*i)])
		if (!if_key(line[*i]))
			break ;
	if (*i == j + 1)
		return (line);
	key = ft_substr(line, j + 1, *i - j - 1);
	if (ft_isdigit(key[0]))
		return (handle_digital_key(line, key, j, i));
	value = ms_find_envp_m(envp, key);
	line_new = handle_char_key(line, value, j, i);
	free (key);
	return (line_new);
}
