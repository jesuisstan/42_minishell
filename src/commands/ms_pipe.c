#include "../../inc/minishell.h"

void	ms_error(char *str)
{
	if (str)
		ft_putendl_fd(str, STDERR_FILENO);
	else
		perror("Error");
	//exit(128); //хер знает какая тут статуса - версия mshmelly
}

static void init_for_pipe(t_msh *msh, t_cmd *cmd)
{
	cmd->is_fork = 0;
	cmd->in = 0;
	cmd->out = 0;
	cmd->pipe_fd[0] = 0;
	cmd->pipe_fd[1] = 0;
	msh->old_out = 0;
	msh->first_cmd = 0;
}

static void	child_proc(t_msh *msh, t_cmd *cmd, t_cmd *start)
{
	if (cmd->rdr)
		ms_redirects(cmd);
	if (msh->first_cmd == 1 && cmd->pipe_fd[1])
		dup2(cmd->pipe_fd[1], STDOUT_FILENO);
	if (!cmd->next && msh->old_out)
	{
		dup2(msh->old_out, STDIN_FILENO);
		close(msh->old_out);
	}
	else if (cmd->next && msh->first_cmd > 1)
	{
		dup2(msh->old_out, STDIN_FILENO);
		dup2(cmd->pipe_fd[1], STDOUT_FILENO);
	}
	while (start->next)
	{
		close(start->pipe_fd[0]);
		close(start->pipe_fd[1]);
		start = start->next;
	}
	ms_command(msh, cmd);
}

static void wail_all(t_cmd *start)
{
	t_cmd	*cmd;
	
	cmd = start;
	while (start->next)
	{
		close(start->pipe_fd[0]);
		close(start->pipe_fd[1]);
		start = start->next;
	}
	while (cmd)
	{
		waitpid(cmd->pid, &g_status.exit, 0);//g_status.exit
		g_status.exit = WEXITSTATUS(g_status.exit); // интерактив статус
		cmd = cmd->next;
	}
}

int	ms_pipex(t_msh *msh, t_cmd *cmd, int len_cmd)
{
	t_cmd	*start;

	init_for_pipe(msh, cmd);
	start = cmd;
	if (!cmd->next && is_builtins(cmd->cmd[0]) && !cmd->rdr)
	{
		ms_command(msh, cmd);
		return (0);
	}
	while (cmd->next)
	{
		if (pipe(cmd->pipe_fd) == -1)
			ms_error(NULL);
		cmd = cmd->next;
	}
	cmd = start;
	while (len_cmd--)
	{
		msh->first_cmd++;
		cmd->pid = fork();
		cmd->is_fork = 1;
		if (cmd->pid < 0)
			ms_error(NULL);
		else if (cmd->pid == 0)
			child_proc(msh, cmd, start);
		msh->old_out = cmd->pipe_fd[0];
		cmd = cmd->next;
	}
	cmd = start;
	wail_all(cmd);
	return (0);
}
