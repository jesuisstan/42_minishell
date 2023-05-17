/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: St.Krivtsov <stan.krivtsov@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:18 by mshmelly          #+#    #+#             */
/*   Updated: 2023/05/17 20:05:45 by St.Krivtsov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern int g_status;

static char	*replace_dollars(char *line, t_envp *envp_l)
{
	int		i;
	int		flag_quote;

	if (!line)
		return (NULL);
	flag_quote = 0;
	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == '$')
			line = ms_manage_dollar(line, &i, envp_l);
		else if (line[i] == '\"' && flag_quote == 0)
			flag_quote = 1;
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
	line = NULL;
	line = readline("minishell § ");
	if (!line)
		exit(g_status);
	if (*line)
		add_history(line);
	return (line);
}

void	ms_parse(t_msh *msh, t_envp *envp_l)
{
	msh->line = read_line_safely(msh->line);
	msh->line = ms_clear_endwhitespaces(msh->line);
	if (!ms_protoparse(msh->line))
	{
		msh->line = replace_dollars(msh->line, envp_l);
		msh->arg = ms_split_line(msh);
		msh->cmd_l = ms_get_commands(msh);
	}
	if (ft_strcmp(msh->line, "") && msh->cmd_l->cmd[0])
		ms_lstfree_arg(&(msh->arg));
	free(msh->line);
}
