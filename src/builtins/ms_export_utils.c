#include "../../inc/minishell.h"

int	print_env_l(t_envp *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(lst->key, STDOUT_FILENO);
		if (lst->value)
		{
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putchar_fd('"', STDOUT_FILENO);
			ft_putstr_fd(lst->value, STDOUT_FILENO);
			ft_putchar_fd('"', STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		lst = lst->next;
	}
	return (0);
}

int	is_key_exist(t_envp **env, char *key)
{
	t_envp	*tmp;

	tmp = (*env);
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
