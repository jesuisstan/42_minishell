// Stas' header

#ifndef MINISHELL_S_H
# define MINISHELL_S_H

# include <stdio.h>

int		ms_print_envp(char **envp);
void	*ms_return_null(char *message);
int		ms_return_nbr(int return_value, char *message);

#endif
