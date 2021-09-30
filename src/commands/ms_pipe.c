#include "../../inc/minishell.h"

void	ms_error(char *str)
{
	if (str)
		ft_putendl_fd("PIZZA", STDOUT_FILENO);
	else
		perror("Error");
	exit(EXIT_FAILURE);
}
//
//void	child_pros(char **argv, char **envp, int *fd, t_msh *msh)
//{
//	int in, out;
//
//	in = open(argv[1], O_RDONLY, 0777);
//	if (in == -1)
//		error();
//	dup2(msh->cmd->out, STDOUT_FILENO);
//	dup2(in, STDIN_FILENO);
//	close(msh->cmd->in);
//	run_command(msh, msh->cmd);
//}
//
//void	parent_pros(char **argv, char **envp, int *fd, t_msh *msh)
//{
//	int	out;
//
//	out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
//	if (out == -1)
//		error();
//	dup2(msh->cmd->in, STDIN_FILENO);
//	dup2(out, STDOUT_FILENO);
//	close(msh->cmd->out);
//	run_command(msh, msh->cmd);
//}
//
//int ms_pipe(char **argv, char **envp, t_msh *msh)
//{
//	int		fd[2];
//	int		pid;
//
//	if (pipe(fd) == -1)
//		error();
//	pid = fork();
//	if (pid == -1)
//		error();
//	if (pid == 0)
//	{
//		child_pros(argv, envp, fd, msh);
//	}
//	wait(NULL);
//	parent_pros(argv, envp, fd, msh);
//	close(fd[0]);
//	close(fd[1]);
//	return (0);
//}

int ms_pipex(t_msh *msh, t_cmd *cmd)
{
	pid_t pid;
	int	status;
	int	pipe_open;
	
	pipe_open = 0;
	if (msh->flag_pipe)
	{
		pipe_open = 1;
		if (pipe(cmd->pipes))
			ms_error(NULL);
	}
	pid = fork();
	if (pid < 0)
		ms_error(NULL);
	else if (pid == 0)
	{
		dup2(cmd->pipes[STDOUT_FILENO], STDOUT_FILENO);
		dup2(msh->old_in, STDIN_FILENO);
		run_command(msh, cmd);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(cmd->pipes[STDOUT_FILENO]);
			if (!cmd->next)
				close (cmd->pipes[STDIN_FILENO]);
		}
		close(msh->old_in);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;
	t_cmd	cmd;
	char **path;
	int i = 0;
	
	msh.flag_pipe = 1;
	msh.old_in = 0;
	msh.old_out = 1;
	msh.cmd = &cmd;
	(void)argc;
	msh.cmd->arg = ft_split("ls", ' ');
	msh.cmd->next = malloc(sizeof ())
	msh.envp_l = ms_clone_envp(envp);
	ms_cp_envp(&msh, envp);
	ms_pipex(&msh, &cmd);
	//	run_command(&msh, msh.cmd);
//	while(path[i++])
//		printf("%s\n", path[i]);
//	print_env_l(msh.envp_l);
	return (0);
}

list 1ls
list 3-l
a
