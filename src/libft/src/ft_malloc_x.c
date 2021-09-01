#include "../inc/libft.h"

void	*ft_malloc_x(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		write(1, "Error malloc\n", 14);
		exit(-1);
	}
	return (ptr);
}
