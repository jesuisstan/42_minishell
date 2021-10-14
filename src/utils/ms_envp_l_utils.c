#include "../../inc/minishell.h"

/*
**	@brief	deletes node of t_envp list. Serves "lstfree_envp"
*/
static void	lstdelone_envp(t_envp *envp_l)
{
	if (!envp_l)
		return ;
	envp_l->content = NULL;
	free (envp_l->key);
	envp_l->key = NULL;
	free (envp_l->value);
	envp_l->value = NULL;
	free (envp_l);
	envp_l = NULL;
}

/*
**	@brief	frees t_envp list
*/
void	lstfree_envp(t_envp **envp_l)
{
	t_envp	*tmp;

	if (!envp_l || !*envp_l)
		return ;
	while (envp_l && *envp_l)
	{
		tmp = (*envp_l)->next;
		lstdelone_envp(*envp_l);
		*envp_l = tmp;
	}
}

/*
**	@brief		finds the key in copy envp
**
**	@param		lst and key envp
**	@return		value
*/
char	*ms_find_envp_l(t_envp **lst, char *key)
{
	t_envp	*tmp;

	if (lst && (*lst) && key)
	{
		tmp = *lst;
		while (tmp)
		{
			if (!ft_strcmp(tmp->key, key))
			{
					return (tmp->value);
			}
			tmp = tmp->next;
		}
	}
	return (NULL);
}

/*
**	@brief		removes one node from t_envp list
**
**	@param		list and key envp
*/
void	lstremove_node_envp(t_envp **envp_l, char *key)
{
	t_envp	*tmp;
	t_envp	*head;
	t_envp	*next_node;

	if (!envp_l || !(*envp_l) || !key)
		return ;
	tmp = *envp_l;
	head = tmp;
	while (tmp->next)
	{
		if (!ft_strcmp(tmp->next->key, key))
		{
			next_node = tmp->next->next;
			lstdelone_envp(tmp->next);
			tmp->next = next_node;
			*envp_l = head;
			break ;
		}
		tmp = tmp->next;
	}
}

int	ms_find_envp_l_and_replace_val(t_envp **envp_l, char *key, char *val)
{
	t_envp	*head;
	t_envp	*tmp;
	char	*tmp_str;

	if (!envp_l || !key || !val)
		return (1);
	tmp = *envp_l;
	head = tmp;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			tmp_str = ft_strjoin(key, "=");
			tmp->content = ft_strjoin(tmp_str, val);
			if (tmp->value)
				free(tmp->value);
			tmp->value = ft_strdup(val);
			*envp_l = head;
			free(tmp_str);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
