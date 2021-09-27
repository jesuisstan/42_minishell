#include "../../inc/minishell.h"

void	del_elem(t_envp **head)
{
	t_envp	*prev = NULL;
	prev = (*head);
	(*head) = (*head)->next;
	free(prev);
}

void	del_Nth(t_envp **head, int n)
{
	t_envp	*prev = NULL;
	t_envp	*cur = NULL;
	
	if (!(*head) || !head)
		return ;
	if (n == 0)
	{
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	else
	{
		cur = (*head);
		while (--n)
		{
			cur = cur->next;
		}
		del_elem(&(cur->next));
	}
}

int	ms_find_envp_l_ind(t_envp *lst, char *key)
{
	int	index;
	t_envp *tmp;
	
	index = 0;
	tmp = lst;
	if (tmp && key)
	{
		while (tmp)
		{
			if (!ft_strcmp(tmp->key, key))
			{
				return (index);
			}
			index++;
			tmp = tmp->next;
		}
	}
	return (0);
}

int	ms_unset(t_msh *msh, char **argv)
{
	int	i;
	int	ind_del;
	
	i = 0;
	if (ms_arrlen(argv) == 1)
		return (0);
	else
	{
		ind_del = ms_find_envp_l_ind(msh->envp_l, argv[1]);
		del_Nth(&(msh->envp_l), ind_del);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;
	int i = 0;
	
	(void)argc;
	msh.envp_l = ms_clone_envp(envp);
	print_env_l(msh.envp_l);
	write(1, "\n\n",2);
	write(1, "Next\n",5);
	ms_unset(&msh, argv);
//	while(envp[i++])
//		printf("%s\n", envp[i]);
	print_env_l(msh.envp_l);
	return (0);
}