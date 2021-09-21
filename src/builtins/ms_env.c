#include "../../inc/minishell.h"

void	ms_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_putendl_fd(envp[i], STDOUT_FILENO);
		i++;
	}
	return ;
}

char	*ms_env_l(t_envp **lst) // на всякий
{
	t_envp *tmp;

	if (lst && (*lst))
	{
		tmp = *lst;
		while (tmp)
		{
			ft_putendl_fd(tmp->content, STDOUT_FILENO);
			tmp = tmp->next;
		}
	}
	return (NULL);
}

//int	main(int argc, char **argv, char **envp)
//{
//	t_msh	msh;

//	(void)argc;
//	msh.envp_l = ms_clone_envp(envp);
//	ms_env_l(&msh.envp_l);
//	return (0);
//}