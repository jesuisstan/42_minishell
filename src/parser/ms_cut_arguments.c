#include "../../inc/minishell.h"

t_arg	*ms_lstnew_arg(char *content, t_msh *g_msh)
{
	t_arg	*arg;
	
	arg = (t_arg *)malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->arg_rare = content;
	arg->arg_pure = ft_strdup(content);
	arg->arg_pure = ms_purify_argument(arg->arg_pure, g_msh);
	arg->next = NULL;
	return (arg);
}

static void	lstadd_back_arg(t_arg **lst, t_arg *new)
{
	t_arg	*last;

	if (lst && (*lst) && new)
	{
		last = *lst;
		if (last == NULL)
			*lst = new;
		else
		{
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	else if (*lst == NULL)
		*lst = new;
}

static int	find_end(char *line, int *flag)
{
	int		i;
	char	spec_sym;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			spec_sym = line[i];
			++i;
			while (line[i] != spec_sym && line[i])
				i++;
		}
		if (ft_strchr(" \t<|>", line[i]))
		{
			if (ft_strchr("<|>", line[i]))
				*flag = 1;
			if (ft_strchr("<|>", line[i]) && ft_strchr("<>", line[i + 1]))
				*flag = 2;
			i += ms_pass_whitespaces(&line[i]);
			return (i);
		}
	}
	return (i);
}

void	ms_cut_arguments(char *line, t_arg **arg, t_msh *g_msh)
{
	int		end;
	int		flag;
	char	*str;

	flag = 0;
	while (*line)
	{
		line += ms_pass_whitespaces(line);
		if (!*line)
			return ;
		end = find_end(line, &flag);
		if (flag != 0)
		{
			str = ft_substr(line, 0, end);
			if (ft_strcmp(str, "\0"))
				lstadd_back_arg(arg, ms_lstnew_arg(str, g_msh));
			lstadd_back_arg(arg, ms_lstnew_arg(ft_substr(line, end, flag), g_msh));
			line += flag;
			flag = 0;
		}
		else
			lstadd_back_arg(arg, ms_lstnew_arg(ft_substr(line, 0, end), g_msh));
		line += end;
	}
}
