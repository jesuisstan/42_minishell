#include "../../inc/minishell.h"

static void	init_for_pipe(t_cmd *cmd)
{
	while (cmd)
	{
		cmd->in = STDIN_FILENO;
		cmd->out = STDOUT_FILENO;
		cmd->is_fork = 0;
		cmd->pipe_fd[0] = 0;
		cmd->pipe_fd[1] = 0;
		cmd = cmd->next;
	}
}

static int	create_pipe(t_cmd *cmd)
{
	t_cmd	*start;

	start = cmd;
	while (cmd->next)
	{
		if (pipe(cmd->pipe_fd) < 0)
			return (ms_not_pipe(start));
		cmd->out = cmd->pipe_fd[1];
		cmd->next->in = cmd->pipe_fd[0];
		cmd = cmd->next;
	}
	return (0);
}

static void	child_proc(t_msh *msh, t_cmd *cmd, t_cmd *start)
{
	ms_redirects(cmd);
	if (ms_dups(cmd))
		ft_putendl_fd("dups", 2);
	while (start->next)
	{
		close(start->pipe_fd[0]);
		close(start->pipe_fd[1]);
		start = start->next;
	}
	ms_command(msh, cmd);
}

static void	wail_all(t_cmd *start)
{
	t_cmd	*cmd;
	int		status;

	status = 0;
	cmd = start;
	while (start->next)
	{
		close(start->pipe_fd[0]);
		close(start->pipe_fd[1]);
		start = start->next;
	}
	while (cmd)
	{
		waitpid(cmd->pid, &status, 0);
		g_status = WEXITSTATUS(status);
		if (!g_status && WIFSIGNALED(status))
		{
			g_status = 128 + WTERMSIG(status);
		}
		cmd = cmd->next;
	}
}

int	ms_pipex(t_msh *msh, t_cmd *cmd, int len_cmd)
{
	t_cmd	*start;

	init_for_pipe(cmd);
	start = cmd;
	if (!cmd->next && is_builtins(cmd->cmd[0]) && !cmd->rdr)
	{
		ms_command(msh, cmd);
		return (0);
	}
	if (create_pipe(cmd))
		return (1);
	while (len_cmd--)
	{
		cmd->pid = fork();
		cmd->is_fork = 1;
		if (cmd->pid < 0)
			ms_error("bash: fork: Resource temporarily unavailable");
		else if (cmd->pid == 0)
			child_proc(msh, cmd, start);
		cmd = cmd->next;
	}
	wail_all(start);
	return (0);
}
