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

void	ms_parse(t_msh *g_msh, char **envp)
{
	int		i;
	int		j;

	g_msh->line = read_line_safely(g_msh->line);
	if (!ms_protoparse(g_msh->line))
	{
		g_msh->envp_l = ms_clone_envp(envp);
		g_msh->arg = ms_split_line(g_msh->line, g_msh);
	}
	free (g_msh->line);
}
