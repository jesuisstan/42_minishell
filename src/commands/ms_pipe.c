#include "../../inc/minishell.h"

void	ms_error(char *str)
{
	if (str)
		ft_putendl_fd(str, STDERR_FILENO);
	else
		perror("Error");
	exit(128); //хер знает какая тут статуса
}

size_t	ms_lstsize(t_cmd *arg)
{
	size_t	i;

	if (!arg)
		return (0);
	i = 0;
	while (arg)
	{
		arg = arg->next;
		i++;
	}
	return (i);
}

int	ms_pipex(t_msh *msh, t_cmd *cmd)
{
	int		len;
	int		first_cmd;
	t_cmd	*start;

	len = 0;
	first_cmd = 0;
	if (!cmd)
		return (0);
	if (!cmd->next && is_builtins(cmd->cmd[0]) && !cmd->rdr)
	{
		ms_command(msh, cmd);
		return (0);
	}
	cmd->is_fork = 0;
	cmd->in = 0;
	cmd->out = 0;
	cmd->pipe_fd[0] = 0;
	cmd->pipe_fd[1] = 0;
	msh->old_out = 0;
	start = cmd;
	len = ms_lstsize(cmd);
	while (cmd->next)
	{
		if (pipe(cmd->pipe_fd) == -1)
			ms_error(NULL);
		cmd = cmd->next;
	}
	cmd = start;
	while (len--)
	{
		first_cmd++;
		cmd->pid = fork();
		cmd->is_fork = 1;
		if (cmd->pid < 0)
			ms_error(NULL);
		else if (cmd->pid == 0)
		{
			if (cmd->rdr)
				ms_redirects(cmd);
			if (first_cmd == 1 && cmd->pipe_fd[1])
				dup2(cmd->pipe_fd[1], STDOUT_FILENO);
			if (!cmd->next && msh->old_out)
			{
				dup2(msh->old_out, STDIN_FILENO);
				close(msh->old_out);
			}
			else if (cmd->next && first_cmd > 1)
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
		msh->old_out = cmd->pipe_fd[0];
		msh->old_in = cmd->pipe_fd[1];
		cmd = cmd->next;
	}
	cmd = start;
	while (start->next)
	{
		close(start->pipe_fd[0]);
		close(start->pipe_fd[1]);
		start = start->next;
	}
	while (cmd)
	{
		waitpid(cmd->pid, NULL, 0); //g_status
		cmd = cmd->next;
	}
	// не выходить если не
	return (0);
}
