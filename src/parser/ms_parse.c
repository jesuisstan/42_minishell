#include "../../inc/minishell.h"

t_arg	*lstnew_arg(char *content, t_msh *g_msh)
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

static t_arg	*ms_split_line(char *line, t_msh *g_msh)
{
	int		i;
	t_arg	*tmp;
	t_arg	*arg;
	
	tmp = lstnew_arg(line, g_msh);
	ms_cut_arguments(line, tmp, g_msh);
	arg = tmp->next;
	free (tmp);
	return (arg);
}

static char	*replace_dollar(char *line, char **envp)
{
	int		i;
	int		flag_quote;

	flag_quote = 0;
	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == '$')
		{
			line = ms_manage_dollar(line, &i, envp);
			printf("line after baks = %s\n", line);}//todo
		else if (line[i] == '\"' && flag_quote == 0)
		{
			flag_quote = 1;
	printf("line = %s\n", line);}//todo
		else if (line[i] == '\"' && flag_quote == 1)
			flag_quote = 0;
		else if (line[i] == '\'' && flag_quote == 0)
		{
			++i;
			while (line[i] != '\'' && line[i])
				i++;
		}
	}
	return (line);
}

static char	*read_line_safely(char *line)
{
	int		i;

	line = NULL;
	line = readline("minishell § ");
	if (!line)
		exit (0); //replace 0 to actual last error status
	if (*line)
		add_history(line);
	return (line);
}

//static char	*pass_end(char *line)
//{
//	char	*line_new;
//	int		i;
//	int		start;

//	i = -1;
//	while (line[++i])
//	{
//		if (line[i] == ' ')//todo
//		{
//			start = i;
//			i += ms_pass_whitespaces(&line[i]);
//			if (line[i] == '\0')
//				return (line_new = ft_substr(line, 0, start));
//		}
//	}
//	return (line);
//}

void	ms_parse(t_msh *g_msh, char **envp)
{
	int		i;
	int		j;

	g_msh->line = read_line_safely(g_msh->line);
//	g_msh->line = pass_end(g_msh->line);
	if (!ms_protoparse(g_msh->line))
	{
		g_msh->envp_l = ms_clone_envp(envp);
		g_msh->line = replace_dollar(g_msh->line,
						ms_envplist_to_array(&(g_msh->envp_l)));
printf("line после замены $ = %s\n", g_msh->line);//todo
		g_msh->arg = ms_split_line(g_msh->line, g_msh);
	}
	free (g_msh->line);
}
