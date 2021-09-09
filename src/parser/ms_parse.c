#include "../../inc/minishell.h"

static char	*manage_quotes(char *line, int *i)
{
	printf("i1 = %d\n", *i);
	printf("manage quotes\n");
	*i += 1;
	printf("i2 = %d\n", *i);
	return (line);
}

static char	*manage_apostrophe(char *line, int *i)
{
	int		j;
	char	*str;

	j = *i + 1;
	str = ft_substr(line, 0, *i);
	*i += 1;
	while (line[*i] != '\'' || line[*i])
	{
		if (line[*i] == '\'')
		{
			str = ft_strjoin(str, ft_substr(line, *i + 1,
						ft_strlen(line) - *i));
			*i -= 2;
			return (str);
		}
		if (line[++*i] == '\'')
		{
			str = ft_strjoin(str, ft_substr(line, j, *i - j));
			*i += 1;
			str = ft_strjoin(str, ft_substr(line, *i, ft_strlen(line) - *i));
			*i -= 2;
			break ;
		}
	}
	return (str);
}

static char	*manage_dollar(char *line, int *i, t_envp **envp_l)
{
	printf("i1 = %d\n", *i);
	printf("manage dollar\n");
	*i += 1;
	printf("i2 = %d\n", *i);
	return (line);
}

static char	*read_line_safely(char *line)
{
	line = NULL;
	line = readline("minishell > ");
	if (!line)
		exit (0); //replace 0 to actual last error status
	if (*line)
		add_history(line);
	return (line);
}

void	ms_parse(t_arguments *arg, char **envp)
{
	char	*line;
	int		i;

	arg->envp_l = ms_clone_envp(envp);
	line = read_line_safely(line);
	if (!ms_protoparse(line))
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == '$')
				line = manage_dollar(line, &i, &(arg->envp_l));
			if (line[i] == '\'')
				line = manage_apostrophe(line, &i);
			if (line[i] == '\"')
				line = manage_quotes(line, &i);
			i++;
		}
		printf("line = %s\n", line); // todo
	}
	free (line);
}
