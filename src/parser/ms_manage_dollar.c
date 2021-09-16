#include "../../inc/minishell.h"

static int	if_key(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

//static int	check_key(char *key)
//{
//	if (c == '_' || ft_isalnum(c))
//		return (1);
//	return (0);
//}

char	*ms_manage_dollar(char *line, int *i, t_envp *envp_l)
{
	int		j;
	char	*line_new;
	char	*key;

	j = *i;
	line_new = ft_substr(line, 0, j);
	while(line[++(*i)])
		if (!if_key(line[*i]))
			break ;
	if (*i == j + 1)
		return (line);
	key = ft_substr(line, j + 1, *i - j - 1);

	if (ft_isdigit(key[0]))
	{
		if (key[0] == '0')
		{
			line_new = ft_strjoin(line_new, ft_strjoin("minishell", &key[1]));
			line_new = ft_strjoin(line_new, ft_strdup(&line[*i]));
			*i = j + ft_strlen(key) + ft_strlen("minishell") - 2;
			printf("HEAR\n");
		}
		else
		{
			if (ft_strlen(key) > 1)
				line_new = ft_strjoin(line_new, &key[1]);
			line_new = ft_strjoin(line_new, ft_strdup(&line[*i]));
			*i = j + ft_strlen(key) - 3;
		}
		free (key);
		free (line);
		return (line_new);
	}


	while (envp_l)
	{
		if (ft_strcmp(key, envp_l->key) == 0)
		{
			line_new = ft_strjoin(line_new, envp_l->value);
			line_new = ft_strjoin(line_new, ft_strdup(&line[*i]));
			*i = j + ft_strlen(envp_l->value) - 1;
			free (key);
			free (line);
			return (line_new);
		}
		envp_l = envp_l->next;
	}
	if (line[*i] == ' ')
		*i += ms_pass_whitespaces(&line[*i]);
	line_new = ft_strjoin(line_new, ft_strdup(&line[*i]));
	*i = j;
	free (key);
	free (line);
	return (line_new);
}
