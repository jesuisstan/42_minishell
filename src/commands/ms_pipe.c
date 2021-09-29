#include "../../inc/minishell.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	child_pros(char **argv, char **envp, int fd)
{
	int in, out;
	
	in = open(argv[1], O_RDONLY, 0777);
	if (in == -1)
		error();
	dup2(fd[1], STDIN_FILENO);
	dup2(in, STDIN_FILENO);
	close(fd[0]);
}

int ms_pipe(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		child_pros(argv, envp, fd);
	}
}



int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;
	t_cmnd	cmnd;
	char **path;
	int i = 0;
	
	msh.cmnd = &cmnd;
	(void)argc;
	msh.cmnd->arg = ft_split("ls -la", ' ');
	
	msh.envp_l = ms_clone_envp(envp);
	ms_cp_envp(&msh, envp);
	run_command(&msh, msh.cmnd);
//	while(path[i++])
//		printf("%s\n", path[i]);
//	print_env_l(msh.envp_l);
	return (0);
}