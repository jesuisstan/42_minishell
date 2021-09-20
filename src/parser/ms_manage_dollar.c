#include "../../inc/minishell.h"

static int	if_key(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

char	*ms_manage_dollar(char *line, int *i, char **envp)
{
	int		j;
	char	*line_new;
	char	*key;
	char	*value;
	char	*tmp_one;
	char	*tmp_two;

	j = *i;
	//tmp_one = ft_substr(line, 0, j);
	while(line[++(*i)])
		if (!if_key(line[*i]))
			break ;
	if (*i == j + 1)
		return (line);
	key = ft_substr(line, j + 1, *i - j - 1);
//	if (ft_isdigit(key[0]))
//	{
//		if (key[0] == '0')
//		{
//			tmp_two = ft_strjoin(tmp_one, ft_strjoin("minishell", &key[1]));
//			line_new = ft_strjoin(tmp_two, ft_strdup(&line[*i]));
//			*i = j + ft_strlen(key) + ft_strlen("minishell") - 2;
//			free (tmp_one);
//			free (tmp_two);
//		}
//		else
//		{
//			if (ft_strlen(key) > 1)
//			{
//				tmp_two = ft_strjoin(tmp_one, &key[1]);
//				line_new = ft_strjoin(tmp_two, ft_strdup(&line[*i]));
//				*i = j + ft_strlen(key) - 2;
//				free (tmp_one);
//				free (tmp_two);
//			}
//			else
//			{
//				line_new = ft_strjoin(tmp_one, ft_strdup(&line[*i]));
//				*i = j - 1;
//				free (tmp_one);
//			}
//		}
//		free (key);
////		free (line);
//		return (line_new);
//	}
	
	value = ms_find_envp(envp, key);
	printf("value = %s\n", value);
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
	}
	//tmp_two = ft_strjoin(ft_substr(line, 0, j), ms_find_envp_l(envp_l, key));
	//printf("tmp_two = %s\n", tmp_two);
	//if (!tmp_two)
	//{
	//	line_new = ft_strjoin(ft_substr(line, 0, j), ft_strdup(&line[*i]));
	//	*i = j - 1;
	//}
	//else
	//{
	//	line_new = ft_strjoin(tmp_two, ft_strdup(&line[*i]));
	//	*i = j + ft_strlen(((*envp_l)->value)) - 1;
	//}
	
	//while (*envp_l)
	//{
	//	if (ft_strcmp(key, (*envp_l)->key) == 0)
	//	{
	//		tmp_two = ft_strjoin(tmp_one, (*envp_l)->value);
	//		line_new = ft_strjoin(tmp_two, ft_strdup(&line[*i]));
	//		*i = j + ft_strlen(((*envp_l)->value)) - 1;
	//		free (key);
	////		free (line);
	//		return (line_new);
	//	}
	//	(*envp_l) = (*envp_l)->next;
	//}
	//line_new = ft_strjoin(tmp_one, ft_strdup(&line[*i]));
	//printf("i = %d\n", *i);
	printf("line_NEW = %s\n", line_new);
	//*i = j - 1;
	//printf("i в конце = %d\n", *i);
	//free (key);
	free (value);
	free (tmp_one);
	free (line);
	return (line_new);
}
