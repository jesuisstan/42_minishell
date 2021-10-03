#include "../../inc/minishell.h"

void	ms_error(char *str)
{
	if (str)
		ft_putendl_fd("PIZZA", STDOUT_FILENO);
	else
		perror("Error");
	exit(EXIT_FAILURE);
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
	int	len, i, first_cmd = 0;
	t_cmd *start;
	
	start = cmd;
	len = ms_lstsize(cmd);
	while (cmd->next)
	{
		if (pipe(cmd->pipe_fd) == -1)
			ms_error(NULL);
		cmd = cmd->next;
		i++;
	}
	cmd = start;
	while (len--)
	{
		first_cmd++;
		
		
		cmd->pid = fork();
		if (cmd->pid < 0)
			ms_error(NULL);
		else if (cmd->pid == 0)
		{
			if (first_cmd == 1)
			{
				dup2(cmd->pipe_fd[1], 1);//Теперь stdout (1) указывает на дескриптор fd,хотя он все еще равен 1, но теперь вывод перенаправляется.
			}
			if (!cmd->next)
			{
				dup2(msh->old_out, 0);
			}
//			else if (first_cmd == 1 && cmd->next)
//			{
//				dup2(cmd->pipe_fd[1], 1)
//			}
			while (start->next)
			{
				close(start->pipe_fd[0]);
				close(start->pipe_fd[1]);
				start = start->next;
			}
			run_command(msh, cmd);
		}
		msh->old_out = cmd->pipe_fd[0];
		msh->old_in = cmd->pipe_fd[1];
		cmd = cmd->next;
	}
	waitpid(start->pid, &i, 0);
	
	
	return (0);
}


int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;
	t_cmd	cmd;
	char **path;
	int i = 0;
	
//	msh.old_in = 0;
//	msh.old_out = 1;
	msh.cmd = &cmd;
	(void)argc;
	msh.cmd->arg = ft_split("ls -la", ' ');
	msh.cmd->next = malloc(sizeof(*msh.cmd) * 1);
	msh.cmd->next->arg = ft_split("wc", ' ');
	msh.cmd->next->next = NULL;
//	msh.cmd->next->next  = malloc(sizeof(*msh.cmd) * 1);
//	msh.cmd->next->next->arg = ft_split("cat -e", ' ');
//	msh.cmd->next->next->next = NULL;
	msh.envp_l = ms_clone_envp(envp);
	ms_cp_envp(&msh, envp);
	ms_pipex(&msh, &cmd);
	//	run_command(&msh, msh.cmd);
//	while(path[i++])
//		printf("%s\n", path[i]);
//	print_env_l(msh.envp_l);
	return (0);
}