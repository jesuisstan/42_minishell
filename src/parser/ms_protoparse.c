#include "../../inc/minishell.h"

static int	check_quote(char *line, int *index)
{
	int		i;
	char	*str;

	str = &line[*index + 1];
	*index += 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\"')
		{
			*index += 1;
			i++;
		}
		if (str[i] == '\"')
			return (EXIT_SUCCESS);
	}
	g_status = 258;
	return (ms_return_nbr(1, "syntax error with unclosed quotes"));
}

static int	check_apostrophe(char *line, int *index)
{
	int		i;
	char	*str;

	str = &line[*index + 1];
	*index += 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\'')
		{
			*index += 1;
			i++;
		}
		if (str[i] == '\'')
			return (EXIT_SUCCESS);
	}
	g_status = 258;
	return (ms_return_nbr(1, "syntax error with unclosed quotes"));
}

static int	check_pipe(char *line, int index)
{
	int		i;
	int		n;
	char	*str;

	str = &line[index];
	i = 0;
	n = ms_pass_whitespaces(&str[i]);
	i += n;
	if (str[i] == '|')
	{
		g_status = 258;
		if (str[i + 1] == '|')
			return (ms_return_nbr(1,
					"syntax error near unexpected token `||'"));
		return (ms_return_nbr(1, "syntax error near unexpected token `|'"));
	}
	if ((str[i] == '|' && str[i + 1] == '|') || str[i] == '\0')
	{
		g_status = 258;
		return (ms_return_nbr(1, "syntax error near unexpected token `|'"));
	}
	return (EXIT_SUCCESS);
}

int	ms_protoparse(char *line)
{
	int	i;

	if (!line)
		return (EXIT_FAILURE);
	i = ms_pass_whitespaces(line);
	if (line[i] == '|')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
		g_status = 258;
		return (EXIT_FAILURE);
	}
	while (line[i])
	{
		if (line[i] == '|' && check_pipe(line, i + 1))
			return (EXIT_FAILURE);
		if (line[i] == '\'' && check_apostrophe(line, &i))
			return (EXIT_FAILURE);
		if (line[i] == '\"' && check_quote(line, &i))
			return (EXIT_FAILURE);
		if ((line[i] == '<' || line[i] == '>')
			&& ms_check_redirect(line, &i, line[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
