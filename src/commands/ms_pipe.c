#include "../../inc/minishell.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	child_pros(char **argv, char **envp, int *fd, t_msh *msh)
{
	int in, out;
	
	in = open(argv[1], O_RDONLY, 0777);
	if (in == -1)
		error();
	dup2(msh->cmd->out, STDOUT_FILENO);
	dup2(in, STDIN_FILENO);
	close(msh->cmd->in);
	run_command(msh, msh->cmd);
}

void	parent_pros(char **argv, char **envp, int *fd, t_msh *msh)
{
	int	out;
	
	out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out == -1)
		error();
	dup2(msh->cmd->in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(msh->cmd->out);
	run_command(msh, msh->cmd);
}

int ms_pipe(char **argv, char **envp, t_msh *msh)
{
	int		fd[2];
	int		pid;
	
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		child_pros(argv, envp, fd, msh);
	}
	wait(NULL);
	parent_pros(argv, envp, fd, msh);
	close(fd[0]);
	close(fd[1]);
	return (0);
}


int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;
	t_cmd	cmd;
	char **path;
	int i = 0;
	
	msh.cmd = &cmd;
	(void)argc;
	msh.cmd->arg = ft_split("ls", ' ');
	
	msh.envp_l = ms_clone_envp(envp);
	ms_cp_envp(&msh, envp);
	ms_pipe(argv, envp, &msh);
	//	run_command(&msh, msh.cmd);
//	while(path[i++])
//		printf("%s\n", path[i]);
//	print_env_l(msh.envp_l);
	return (0);
}