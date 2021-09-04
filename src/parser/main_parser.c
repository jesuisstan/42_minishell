// gcc *.c ../utils/*.c ../libft/libft.a -o parser
#include "../../inc/minishell.h"

int	main(void)
{
	t_arguments	*arguments;
	
	ms_parse(arguments);
	return (0);
}
