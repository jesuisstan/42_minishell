#include "../../inc/minishell.h"

static int	check_pipe(char *line, int index)
{
	int		i;
	int		n;
	char	*str;

	str = &line[index];
	i = 0;
	n = ms_pass_whitespaces(&str[i]);
	i += n;
	if (str[i] == '\0')
		return (ms_return_nbr(1, "syntax error near unexpected token `|'"));
	if (str[i] == '|' && n > 0)
	{
		if (str[i + 1] == '|')
			return (ms_return_nbr(1,
					"syntax error near unexpected token `||'"));
		return (ms_return_nbr(1, "syntax error near unexpected token `|'"));
	}
	if (str[i] == '|' && str[i + 1] == '|')
		return (ms_return_nbr(1, "syntax error near unexpected token `|'"));
	return (0);
}

void	ms_protoparse(char *line)
{
	int	i;
	int	n;

	i = ms_pass_whitespaces(line);
	if (line[i] == '|')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'",
			STDERR_FILENO);
		return ;
	}
	while (line[i])
	{
		if (line[i] == '|' && check_pipe(line, i + 1))
			break ;
		i++;
	}
}
