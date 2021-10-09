#include "../../inc/minishell.h"

char	*get_key(char *content)
{
	char	*key;
	int		i;

	i = 0;
	while (content[i] != '=' && content[i] != '\0')
		i++;
	key = ft_substr(content, 0, i);
	return (key);
}

char	*get_value(char *content)
{
	char	*value;
	int		i;

	i = 0;
	while (content[i] != '=' && content[i] != '\0')
		i++;
	if (content[i] == '\0')
		value = NULL;
	else
		value = ft_strdup(&content[i + 1]);
	return (value);
}

void	lstadd_back_envp(t_envp **envp_l, t_envp *new)
{
	t_envp	*last;

	if (envp_l && (*envp_l) && new)
	{
		last = *envp_l;
		if (last == NULL)
			*envp_l = new;
		else
		{
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	else if (*envp_l == NULL)
		*envp_l = new;
}

t_envp	*lstnew_envp(char *content)
{
	t_envp	*list;

	list = (t_envp *)malloc(sizeof(t_envp));
	if (!list)
		return (NULL);
	list->content = content;
	list->key = get_key(content);
	list->value = get_value(content);
	list->next = NULL;
	return (list);
}

t_envp	*ms_clone_envp(char **envp)
{
	t_envp	*envp_l;
	int		i;

	envp_l = NULL;
	i = -1;
	while (envp[++i])
		lstadd_back_envp(&envp_l, lstnew_envp(envp[i]));
	return (envp_l);
}
