// Stas' header

#ifndef MINISHELL_S_H
# define MINISHELL_S_H

# include <stdio.h>

typedef struct s_arguments
{
	/* data */
}	t_arguments;

int		ms_protoparse(char *line);
void	ms_parse(t_arguments *arguments);

void	*ms_return_null(char *message);
int		ms_return_nbr(int return_value, char *message);

#endif
