#include "../../inc/minishell.h"

int	ms_env(t_envp *lst)
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

//int	main(int argc, char **argv, char **envp)
//{
//	t_msh	msh;
//
//	(void)argc;
//	msh.envp_l = ms_clone_envp(envp);
//	ms_env(msh.envp_l);
//	ft_putendl_fd("\n", 1);
//	ms_env(msh.envp_l);
//	ft_putendl_fd("\n", 1);
//	ms_env(msh.envp_l);
//	ft_putendl_fd("\n", 1);
//	ms_env(msh.envp_l);
//	return (0);
//}