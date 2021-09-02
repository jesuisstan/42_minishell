// prints in STD_ERROR error's description ("message") & returns "return_value"

#include "../../inc/minishell.h"

void	*ms_return_null(char *message)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, message, ft_strlen(message));
	write(STDERR_FILENO, "\n", 1);
	return (NULL);
}

int	ms_return_nbr(int return_value, char *message)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, message, ft_strlen(message));
	write(STDERR_FILENO, "\n", 1);
	return (return_value);
}
