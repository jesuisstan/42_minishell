#include "../../inc/minishell.h"

static void	lstadd_back_arg(t_arg **lst, t_arg *new)
{
	t_arg	*last;

	if (lst && (*lst) && new)
	{
		last = (*lst);
		if (last == NULL)
			(*lst) = new;
		else
		{
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
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
			i += ms_pass_whitespaces(&line[i]);
			return (i);
		}
	}
	return (i);
}

void	ms_cut_arguments(char *line, t_arg *arg, t_msh *g_msh)
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
				lstadd_back_arg(&arg, lstnew_arg(str, g_msh));
			lstadd_back_arg(&arg, lstnew_arg(ft_substr(line, end, 1), g_msh));
			line += 1;
			flag = 0;
		}
		else
			lstadd_back_arg(&arg, lstnew_arg(ft_substr(line, 0, end), g_msh));
		line += end;
	}
}
