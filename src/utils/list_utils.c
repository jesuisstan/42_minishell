#include "../../inc/minishell.h"

t_envp	*ft_lstlast(t_envp *lst)
{
	t_envp	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_envp **lst, t_envp *new)
{
	t_envp	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
