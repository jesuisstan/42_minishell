#include "../../inc/minishell.h"

void	ms_error(char *str)
{
	if (str)
		ft_putendl_fd(str, STDERR_FILENO);
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

int ms_pipex(t_msh *msh, t_cmd *cmd)
{
	int	len, i, first_cmd;
	len = 0;
	i = 0;
	first_cmd = 0;
	t_cmd *start;
	if (!cmd)
		return (0);
//	if (!cmd->next && is_builtins(cmd->cmd[0]))
//		ms_command(msh, cmd); надо допилить
//	cmd->in = 0;
//	cmd->out = 0;
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
				dup2(cmd->pipe_fd[1], 1);
			}
			if (!cmd->next)
			{
				dup2(msh->old_out, 0);
			}
			else if (cmd->next && first_cmd > 1)
			{
				dup2(msh->old_out, 0);
				dup2(cmd->pipe_fd[1], 1);
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
	while (start->next)
	{
		close(start->pipe_fd[0]);
		close(start->pipe_fd[1]);
		start = start->next;
	}
	waitpid(start->pid, &i, 0);
	// Тарас сказал чтото ждать в цикле
	return (0);
}


//gcc src/commands/ms_pipe.c  src/commands/ms_command.c src/commands/ms_path.c src/commands/ms_builtin.c src/utils/ms_arrlen.c src/parser/ms_clone_envp.c src/utils/ms_find_envp.c src/utils/ms_malloc_x.c ./src/libft/libft.a src/builtins/*.c && ./a.out


//int	main (int argc, char **argv, char **envp)
//{
//	t_msh	msh;
//	t_cmd	cmd;
//	char **path;
//	int i = 0;

//	msh.cmd_l = &cmd;
//	(void)argc;
//	msh.cmd_l->cmd = ft_split("ls -la", ' ');
//	msh.cmd_l->next = malloc(sizeof(*msh.cmd_l) * 1);
//	msh.cmd_l->next->cmd = ft_split("cat", ' ');
//	msh.cmd_l->next->next  = malloc(sizeof(*msh.cmd_l) * 1);
//	msh.cmd_l->next->next->cmd = ft_split("wc", ' ');
//	msh.cmd_l->next->next->next = NULL;
////	msh.cmd->next->next->next  = malloc(sizeof(*msh.cmd_l) * 1);
////	msh.cmd->next->next->next->arg = ft_split("wc", ' ');
////	msh.cmd->next->next->next->next  = malloc(sizeof(*msh.cmd_l) * 1);
////	msh.cmd->next->next->next->next->arg = ft_split("wc -l", ' ');
////	msh.cmd->next->next->next->next->next  = malloc(sizeof(*msh.cmd_l) * 1);
////	msh.cmd->next->next->next->next->next->arg = ft_split("cat -e", ' ');
////	msh.cmd->next->next->next->next->next->next = NULL;
//	msh.envp_l = ms_clone_envp(envp);
//	ms_cp_envp(&msh, envp);
//	ms_pipex(&msh, &cmd);
//	//	ms_command(&msh, msh.cmd);
////	while(path[i++])
////		printf("%s\n", path[i]);
////	print_env_l(msh.envp_l);
//	return (0);
//}