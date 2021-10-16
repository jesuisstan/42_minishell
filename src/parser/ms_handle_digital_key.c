#include "../../inc/minishell.h"

static char	*handle_numberfull(char *line, char *key, int j, int *i)
{
	char	*line_new;
	char	*tmp_one;
	char	*tmp_two;
	char	*tmp_three;
	char	*tmp_four;

	line_new = NULL;
	tmp_one = NULL;
	tmp_two = NULL;
	tmp_three = NULL;
	tmp_four = NULL;
	tmp_one = ft_substr(line, 0, j);
	tmp_two = ft_strdup(&key[1]);
	tmp_three = ft_strjoin(tmp_one, tmp_two);
	tmp_four = ft_strdup(&line[*i]);
	line_new = ft_strjoin(tmp_three, tmp_four);
	*i = j + ft_strlen(key) - 2;
	free(tmp_one);
	free(tmp_two);
	free(tmp_three);
	free(tmp_four);
	return (line_new);
}

static char	*handle_zero(char *line, char *key, int j, int *i)
{
	char	*line_new;
	char	*tmp_one;
	char	*tmp_two;
	char	*tmp_three;
	char	*tmp_four;

	line_new = NULL;
	tmp_one = NULL;
	tmp_two = NULL;
	tmp_three = NULL;
	tmp_four = NULL;
	tmp_one = ft_substr(line, 0, j);
	tmp_two = ft_strjoin("minishell", &key[1]);
	tmp_three = ft_strjoin(tmp_one, tmp_two);
	tmp_four = ft_strdup(&line[*i]);
	line_new = ft_strjoin(tmp_three, tmp_four);
	*i = j + ft_strlen(key) + ft_strlen("minishell") - 2;
	free(tmp_one);
	free(tmp_two);
	free(tmp_three);
	free(tmp_four);
	return (line_new);
}

char	*ms_handle_digital_key(char *line, char *key, int j, int *i)
{
	char	*line_new;
	char	*tmp_one;
	char	*tmp_two;

	if (key[0] == '0')
		line_new = handle_zero(line, key, j, i);
	else if (ft_strlen(key) > 1)
		line_new = handle_numberfull(line, key, j, i);
	else
	{
		tmp_one = ft_substr(line, 0, j);
		tmp_two = ft_strdup(&line[*i]);
		line_new = ft_strjoin(tmp_one, tmp_two);
		*i = j - 1;
		free(tmp_one);
		free(tmp_two);
	}
	free(key);
	free(line);
	return (line_new);
}
