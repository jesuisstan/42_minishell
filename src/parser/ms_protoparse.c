#include "../../inc/minishell.h"

static int	pass_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
		   || line[i] == '\v' || line[i] == '\r' || line[i] == '\f')
		i++;
	return (i);
}

//static int	manage_spec_symbols(char *line)
//{
//	int	i;

//	i = 0;
//	if (line[i] == '\\')
//		{
//			if (line[i + 1] == '\0')
//				return (ms_return_nbr(EXIT_FAILURE,
//					"syntax error near unexpected token `\\'"));
//			i += 2;
//		}
//		if (line[i] == ';')
//		{
//			if (line[i + 1] == ';' || line[i + 1] == '|')
//				return (ms_return_nbr(EXIT_FAILURE,
//					"syntax error near unexpected token `;'"));
//			i += 2;
//		}
//		if (line[i] == '|')
//		{
//			if (line[i + 1] == '|' && line[i + 2] == '|')
//				return (ms_return_nbr(EXIT_FAILURE,
//					"syntax error near unexpected token `|'"));
//			i += 2;
//		}
//}

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
	int		n;

	i = pass_spaces(line);
	if (line[i] == ';')
		return (ms_return_nbr(EXIT_FAILURE,
			"syntax error near unexpected token `;'"));
	if (line[i] == '|')
		return (ms_return_nbr(EXIT_FAILURE,
			"syntax error near unexpected token `|'"));
	while (line[i])
	{
		if (line[i] == '\\')
		{
			if (line[i + 1] == '\0')
				return (ms_return_nbr(EXIT_FAILURE,	"syntax error near unexpected token `\\'"));
			i += 2;
		}
		if (line[i] == ';')
		{
			i += 1;
			n = pass_spaces(&line[i]);
			if (n > 0)
				i += n;
			if (line[i] == ';')
				return (ms_return_nbr(EXIT_FAILURE,
					"syntax error near unexpected token `;'"));
			if (line[i] == '|')
				return (ms_return_nbr(EXIT_FAILURE,
					"syntax error near unexpected token `|'"));
		}
		if (line[i] == '|')
		{
			i += 1;
			n = pass_spaces(&line[i]);
			if (n > 0)
				i += n;
			if (line[i] == '|' && line[i + 2] == '|')
				return (ms_return_nbr(EXIT_FAILURE,
					"syntax error near unexpected token `|'"));
			i += 2;
		}
		if (line[i] == '\'')
			i += check_apostrophe(line, i + 1);
		if (line[i] == '\"')
			i += check_quote(line, i + 1);
		i++;
	}
	printf("COOL\n");//todo
	return (0);
}
