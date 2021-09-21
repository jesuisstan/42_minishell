#include "../../inc/minishell.h"

int	ft_strcmp_env(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	swap_action(t_envp **lst)
{
	t_envp	*tmp;

	if ((*lst) || (*lst)->next)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		(*lst)->next = tmp;
	}
}

static void	sorting(t_envp *lst)
{
	t_envp	*start;
	t_envp	*tmp;
	int flag;
	
	if (!lst)
		return ;
	start = lst;
	while (start->next)
	{
		flag = 0;
		tmp = start;
		while (tmp->next)
		{
			if (ft_strcmp_env(tmp->key, tmp->next->key) > 0)
			{
				swap_action(&tmp);
				flag = 1;
			}
			tmp = tmp->next;
		}
		if (flag == 0)
			break ;
	}
	return ;
}

int	ms_export(t_msh *msh, char **argv)
{
	//if (ms_arrlen(argv) == 1)
	//{
		sorting(msh->envp_l);
	//}
	
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;

	(void)argc;
	msh.envp_l = ms_clone_envp(envp);
	ms_export(&msh, argv);
	while (msh.envp_l)
	{
		printf ("%s\n", msh.envp_l->key);
		msh.envp_l = msh.envp_l->next;
	}
	
	
	return (0);
}