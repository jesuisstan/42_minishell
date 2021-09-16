#include "../../inc/minishell.h"

static char	*get_key(char *content)
{
	char	*key;
	int		i;

	i = 0;
	while (content[i] != '=' && content[i] != '\0')
		i++;
	key = ft_substr(content, 0, i);
	return (key);
}

static char	*get_value(char *content)
{
	char	*value;
	int		i;

	i = 0;
	while (content[i] != '=' && content[i] != '\0')
		i++;
	value = ft_strdup(&content[i + 1]);
	return (value);
}

static t_envp	*lstnew_envp(char *content)
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

	i = 0;
	envp_l = lstnew_envp(envp[i]);
	while (envp[++i])
		ft_lstadd_back(&envp_l, lstnew_envp(envp[i]));
	return (envp_l);
}
