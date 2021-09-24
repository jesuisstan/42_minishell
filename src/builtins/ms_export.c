#include "../../inc/minishell.h"

int	ft_strcmp_env(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	return (s1[i] - s2[i]);
}

void	swap_action(t_envp **lst)
{
	t_envp	*tmp;

	if ((*lst) || (*lst)->next || (*lst)->next->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		tmp->next = (*lst);
		(*lst) = tmp;
	}
}

static void	sorting(t_envp **lst)
{
	int flag = 0;
	t_envp	*cur;
	
	if (!(*lst) || !(*lst)->next)
		return ;
	if (ft_strcmp((*lst)->content, (*lst)->next->content) > 0)
		swap_action(lst);
	cur = (*lst);
	while (cur->next->next)
	{
		if (strcmp(cur->next->content, cur->next->next->content) > 0)
		{
			swap_action(&(cur->next));
			flag++;
		}
		cur = cur->next;
	}
	if (flag)
		sorting(lst);
}

int	ms_export(t_msh *msh, char **argv)
{
	if (ms_arrlen(argv) == 1)
	{
		sorting(&msh->envp_l);
	}
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
		printf ("%s\n", msh.envp_l->content);
		msh.envp_l = msh.envp_l->next;
	}
	
	
	return (0);
}