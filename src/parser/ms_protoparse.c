#include "../../inc/minishell.h"

static int	check_semicolon(char *line, int index)
{
	int		i;
	int		n;
	char	*str;

	str = &line[index];
	i = 0;
	n = ms_pass_whitespaces(&str[i]);
	if (n > 0)
		i += n;
	if (str[i] == ';')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;'",
			STDOUT_FILENO);
		exit (EXIT_FAILURE);
	}
	if (str[i] == '|')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'",
			STDOUT_FILENO);
		exit (EXIT_FAILURE);
	}
	return (i);
}

static int	check_pipe(char *line, int index)
{
	int		i;
	int		n;
	char	*str;

	str = &line[index];
	i = 0;
	n = ms_pass_whitespaces(&str[i]);
	if (n > 0)
		i += n;
	if (str[i] == '\0')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 1);
		exit (EXIT_FAILURE);
	}
	if (str[i] == '|')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 1);
		exit (EXIT_FAILURE);
	}
	if (str[i] == ';')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;'", 1);
		exit (EXIT_FAILURE);
	}
	return (i);
}

static int	check_quote(char *line, int index)
{
	int		i;
	char	*str;

	str = &line[index];
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\')
			i += 2;
		if (str[i] != '\"')
			i++;
		if (str[i] == '\"')
		{
			i++;
			return (i);
		}
	}
	ft_putendl_fd("minishell: syntax error with unclosed quotes",
		STDOUT_FILENO);
	exit (EXIT_FAILURE);
}

static int	check_apostrophe(char *line, int index)
{
	int		position;
	int		i;
	char	*str;

	str = &line[index];
	position = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\'')
		{
			position++;
			i++;
		}
		if (str[i] == '\'')
		{
			position++;
			return (position);
		}
	}
	ft_putendl_fd("minishell: syntax error with unclosed quotes",
		STDOUT_FILENO);
	exit (EXIT_FAILURE);
}

int	ms_protoparse(char *line)
{
	int		i;

	i = ms_pass_whitespaces(line);
	if (line[i] == ';' || line[i] == '|')
		return (ms_return_nbr(1, "syntax error near unexpected token ; or |"));
	while (line[i])
	{
		if (line[i] == '\\')
		{
			if (line[i + 1] == '\0')
				return (ms_return_nbr(EXIT_FAILURE,
						"syntax error near unexpected token `\\'"));
			i += 2;
		}
		if (line[i] == ';')
			i += check_semicolon(line, i + 1);
		if (line[i] == '|')
			i += check_pipe(line, i + 1);
		if (line[i] == '\'')
			i += check_apostrophe(line, i + 1);
		if (line[i] == '\"')
			i += check_quote(line, i + 1);
		i++;
	}
	return (0);
}
