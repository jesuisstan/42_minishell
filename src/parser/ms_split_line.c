#include "../../inc/minishell.h"

static t_arg	*lstnew_arg(char *content, int index)
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->index = index;
	arg->arg_rare = ft_strdup(content);
	arg->next = NULL;
	free (content);//todo
	return (arg);
}

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

static int	find_end(char *line)
{
	int		i;

	i = ms_pass_whitespaces(line);
	while (!ft_iswhitespace(line[i]) && line[i] != '|' && line[i] != '<' && line[i] != '>' && line[i] != '\0')
		i++;
	return (i);
}

static char	*cut_argument(char *line, t_arg *arg, int index) // version 2
{
	int		start;
	int		end;
	char	*str;
	char	*line_new;

	start = ms_pass_whitespaces(line);
	end = find_end(line);
printf("end = %d\n", end);//todo
	str = ft_substr(line, start, end - start);
printf("str = %s\n", str);//todo
	lstadd_back_arg(&arg, lstnew_arg(str, index));

	line_new = ft_strdup(&line[end + 1]);
printf("line_new = %s\n", line_new);//todo
	return (line_new);
}

//static char	*cut_argument(char *line, t_arg *arg, int index) // version 1
//{
//	int		i;
//	int		start;
//	int		end;
//	char	*str;
//	char	*line_new;

//	//i = 0;
//	i = ms_pass_whitespaces(line);
//	printf("i в начале = %d", i);
//	start = i;
//	while (line[i] != '\0')
//	{
//		//if (line[i] == '\'')
//		//	while (line[i] != '\'')
//		//		i++;
//		//if (line[i] == '\"')
//		//	while (line[i] != '\"')
//		//		i++;
//		if (ft_iswhitespace(line[i]) || line[i] == '|' || line[i] == '<' || line[i] == '>')
//			break ;
//		i++;
//	}
//	str = ft_substr(line, start, i);
//	printf("str = %s\n", str);//todo
//	lstadd_back_arg(&arg, lstnew_arg(str, index));
//	line_new = ft_strdup(&line[i + 1]);
//	return (line_new);
//}

t_arg	*ms_split_line(char *line)
{
	int		i;
	int		index;
	t_arg	*arg;

	index = -1;
	arg = lstnew_arg(line, index);
	//i = 0;
	while (*line)
	{
		index += 1;
		line = cut_argument(line, arg, index);
		//printf("new_line = %s\n", line);//todo
		//i++;
	}
	return (arg);
}