#include "../inc/minishell.h"

void	*ms_malloc_x(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("minishell");
		exit(-1);
	}
	return (ptr);
}
