/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshmelly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:18 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/17 18:58:18 by mshmelly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	rdr_right(t_cmd *cmd, char *file, int mod)
{
	if (mod == RDR_R1)
		cmd->out = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (mod == RDR_R2)
		cmd->out = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmd->out == -1)
	{
		perror("Error");
		g_status = 1;
		exit(g_status);
	}
}

static void	rdr_left(t_cmd *cmd, char *file, int mod)
{
	if (mod == RDR_L1)
	{
		cmd->in = open(file, O_RDONLY);
		if (cmd->in == -1)
		{
			perror("Error");
			g_status = 1;
			exit(g_status);
		}
	}
}

static void	heredoc(t_cmd *cmd, char *stop)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!ft_strncmp(line, stop, ft_strlen(stop) + 1))
			break ;
		ft_putendl_fd(line, cmd->out);
		free(line);
	}
	close(cmd->out);
	exit(0);
}

static void	rdr_double_left(t_cmd *cmd, char *stop)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) < 0)
	{
		perror("Error");
		g_status = 1;
		exit (g_status);
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		cmd->out = fd[1];
		heredoc(cmd, stop);
	}
	else
	{
		close(fd[1]);
		waitpid(pid, NULL, 0);
		cmd->in = fd[0];
	}
}

int	ms_redirects(t_cmd *cmd)
{
	t_rdr	*rdr;

	rdr = cmd->rdr;
	while (rdr)
	{
		if (!ft_strncmp(rdr->name, ">>", 2))
			rdr_right(cmd, (rdr->name + 2), RDR_R2);
		else if (!ft_strncmp(rdr->name, ">", 1))
			rdr_right(cmd, (rdr->name + 1), RDR_R1);
		else if (!ft_strncmp(rdr->name, "<<", 2))
			rdr_double_left(cmd, (rdr->name + 2));
		else if (!ft_strncmp(rdr->name, "<", 1))
			rdr_left(cmd, (rdr->name + 1), RDR_L1);
		rdr = rdr->next;
	}
	return (0);
}
