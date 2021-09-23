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

	if ((*lst) || (*lst)->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		tmp->next = (*lst);
		(*lst) = tmp;
	}
}

static size_t	ms_lstsize_env(t_envp **lst)
{
	size_t	i;
	t_envp	*tmp;

	if (!lst || !(*lst))
		return (-1);
	tmp = (*lst);
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static void	sorting(t_envp **lst)
{
	t_envp	*a, *b, *p, *h, *i = NULL;

	if (!lst)
		return ;
	//int len = ms_lstsize_env(&lst);
	for (i = (*lst); i != NULL; )
	{
		a = i;
		i = i->next;
		b = h;
		for (p = NULL; ((b != NULL) && (strcmp(b->key, a->key))); )
		{
			p = b;
			b = b->next;
			//if (ft_strcmp_env(tmp->key, tmp->next->key) > 0)
			//	swap_action(&tmp);
		}
		if (p == NULL)
		{
			a->next = h;
			h = a;
		}
		else
		{
			a->next = b;
			p->next = a;
		}
	}
	if (h != NULL)
		(*lst) = h;
	return ;
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

	//while (msh.envp_l)
	//{
	//	printf ("%s\n", msh.envp_l->key);
	//	msh.envp_l = msh.envp_l->next;
	//}
	
	
	return (0);
}