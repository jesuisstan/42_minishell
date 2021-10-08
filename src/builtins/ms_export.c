#include "../../inc/minishell.h"

void	print_env_l(t_envp *lst)
{
	if (!lst)
		return ;
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
}

static void	swap_action(t_envp **lst)
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

int	not_valid(char *agr)
{
	ft_putstr_fd (MSH, STDERR_FILENO);
	ft_putstr_fd("export`", STDERR_FILENO);
	ft_putstr_fd(agr, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
	return (1);
}

int	check_export(char *arg)
{
	int	i;
	
	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isdigit(arg[0]) || !ft_isalpha(arg[0]))
			return (not_valid(arg));
		if (!ft_isdigit(arg[i]) && !ft_isalpha(arg[i]))
			return (not_valid(arg));
		i++;
	}
	return 0;
}


int	ms_export(t_msh *msh, char **argv)
{
	int	i;

	i = 1;
	if (ms_arrlen(argv) == 1)
	{
		sorting(&msh->envp_l);
		print_env_l(msh->envp_l);
		return (0);
	}
	while (argv[i])
	{
		if (check_export(argv[i]))
			return (1);
		lstadd_back_envp(&msh->envp_l, lstnew_envp(argv[i]));
		i++;
	}
	return (0);
}
