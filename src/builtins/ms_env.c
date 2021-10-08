#include "../../inc/minishell.h"

int	ms_env(t_envp *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		ft_putstr_fd(lst->key, STDOUT_FILENO);
		if (lst->value)
		{
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd(lst->value, STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		lst = lst->next;
	}
	return (0);
}
