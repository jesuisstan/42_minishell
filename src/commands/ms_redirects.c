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
	dup2(cmd->out, 1);
	close(cmd->out);
	dup2(cmd->in, STDIN_FILENO);
	close(cmd->in);
	//еще дап в СТДАУТ если нет следующего элемента в листе редиректов
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
	//еще дап в СТДин если нет следующего элемента в листе редиректов
}

void	heredoc(t_cmd *cmd, char *stop)
{
	char	*line;
	
	while (1)
	{
		line = readline("> ");
		if(!ft_strncmp(line, stop, ft_strlen(stop)))
			break ;
		ft_putendl_fd(line, cmd->out); // попробовать отправить в СТДАУТ
		free(line);
	}
	close(cmd->out);
	exit(0);
}

void	rdr_double_left(t_cmd *cmd, char *stop)
{
	int	fd[2];
	int	pid;
	
	if(pipe(fd) == -1)
		ms_error(NULL);
	pid = fork();
	if (pid == 0) //child process
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

int	ms_redirects(t_msh *msh, t_cmd *cmd)
{
	t_rdr	*rdr;

	rdr = cmd->rdr;
	(void)msh;
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
		else {
			ft_putendl_fd("KAKAYA TO HYETA?", 1);
			exit(0);
		}
		rdr = rdr->next;
	}
	return (0);
}
//
//int	main (int argc, char **argv, char **envp)
//{
//	t_msh	msh;
//	t_cmd	cmd;
//	char **path;
//	int i = 0;
//	msh.cmd_l = &cmd;
//	(void)argc;
//	msh.cmd_l->cmd = ft_split("ls -la", ' ');
//	msh.cmd_l->rdr = malloc(sizeof (*msh.cmd_l->rdr));
//	msh.cmd_l->rdr->name = ft_strdup(argv[1]);
//	msh.cmd_l->next = NULL;
////	msh.cmd_l->next->next  = malloc(sizeof(*msh.cmd_l) * 1);
////	msh.cmd_l->next->next->cmd = ft_split("wc", ' ');
////	msh.cmd_l->next->next->next = NULL;
//	//	msh.cmd->next->next->next  = malloc(sizeof(*msh.cmd_l) * 1);
//	//	msh.cmd->next->next->next->arg = ft_split("wc", ' ');
//	//	msh.cmd->next->next->next->next  = malloc(sizeof(*msh.cmd_l) * 1);
//	//	msh.cmd->next->next->next->next->arg = ft_split("wc -l", ' ');
//	//	msh.cmd->next->next->next->next->next  = malloc(sizeof(*msh.cmd_l) * 1);
//	//	msh.cmd->next->next->next->next->next->arg = ft_split("cat -e", ' ');
//	//	msh.cmd->next->next->next->next->next->next = NULL;
//	msh.envp_l = ms_clone_envp(envp);
//	ms_cp_envp(&msh, envp);
//	ms_redirects(&msh, &cmd);
//	ms_pipex(&msh, &cmd);
//	//	ms_command(&msh, msh.cmd);
//	//	while(path[i++])
//	//		printf("%s\n", path[i]);
//	//	print_env_l(msh.envp_l);
//	return (0);
//}
