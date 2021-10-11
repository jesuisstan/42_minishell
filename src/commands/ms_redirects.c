#include "../../inc/minishell.h"

static void	ms_error(char *str)
{
	if (str)
		ft_putendl_fd(str, STDERR_FILENO);
	else
		perror("Error");
	exit(EXIT_FAILURE);//хер знает какая тут статуса
}

void	rdr_right(t_cmd *cmd, char *file, int mod)
{
	if (mod == RDR_R1)
		cmd->out = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (mod == RDR_R2)
		cmd->out = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmd->out == -1)
		ms_error(NULL);
	dup2(cmd->out, STDOUT_FILENO);
	close(cmd->out);
}

void	rdr_left(t_cmd *cmd, char *file, int mod)
{
	if (mod == RDR_L1)
	{
		if (cmd->in != STDIN_FILENO)
			close(cmd->in);
		cmd->in = open(file, O_RDONLY);
		if (cmd->in == -1)
			ms_error(NULL);
	}
}

void	heredoc(t_cmd *cmd, char *stop)
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

void	rdr_double_left(t_cmd *cmd, char *stop)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		ms_error(NULL);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		cmd->out = fd[1];
		heredoc(cmd, stop);
	}
	else
	{
		waitpid(pid, NULL, 0);
		cmd->in = fd[0];
		close(fd[1]);
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
	if (cmd->in != STDIN_FILENO)
	{
		dup2(cmd->in, STDIN_FILENO);
		close(cmd->in);
	}
	return (0);
}
