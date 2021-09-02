#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <fcntl.h>
# include "../src/libft/inc/libft.h"

# include "./minishell_a.h"
# include "./minishell_s.h"

void	*ms_malloc_x(size_t size);

#endif
