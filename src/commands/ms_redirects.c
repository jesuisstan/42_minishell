#include "../../inc/minishell.h"

static void	ms_error(char *str)
{
	if (str)
		ft_putendl_fd(str, STDOUT_FILENO);
	else
		perror("Error");
	exit(EXIT_FAILURE);
}

void	rdr_open_file(t_cmd *cmd, char *file, int mod)
{
	if (mod == RDR_R1)
	{
		cmd->out = open(file, O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (cmd->out == -1)
			ms_error(NULL);
		dup2(cmd->out, 1);
		close(cmd->out);
	}
	else if (mod == RDR_R2)
	{
		cmd->out = open(file, O_WRONLY | O_CREAT | O_APPEND  , 0777);
		if (cmd->out == -1)
			ms_error(NULL);
		dup2(cmd->out, 1);
		close(cmd->out);
	}
}

int	ms_redirects(t_msh *msh, t_cmd *cmd)
{
	if (!ft_strncmp(cmd->rdr->name, ">>", 2))
		rdr_open_file(cmd, (cmd->rdr->name + 2), RDR_R2);
	else if (!ft_strncmp(cmd->rdr->name, ">", 1))
		rdr_open_file(cmd, (cmd->rdr->name + 1), RDR_R1);
	else
	{ft_putendl_fd("KAKAYA TO HYETA?", 1); exit(0);}
	return (0);
}

int	main (int argc, char **argv, char **envp)
{
	t_msh	msh;
	t_cmd	cmd;
	char **path;
	int i = 0;
	msh.cmd_l = &cmd;
	(void)argc;
	msh.cmd_l->cmd = ft_split("ls -la", ' ');
	msh.cmd_l->rdr = malloc(sizeof (*msh.cmd_l->rdr));
	msh.cmd_l->rdr->name = ft_strdup(argv[1]);
	msh.cmd_l->next = NULL;
//	msh.cmd_l->next->next  = malloc(sizeof(*msh.cmd_l) * 1);
//	msh.cmd_l->next->next->cmd = ft_split("wc", ' ');
//	msh.cmd_l->next->next->next = NULL;
	//	msh.cmd->next->next->next  = malloc(sizeof(*msh.cmd_l) * 1);
	//	msh.cmd->next->next->next->arg = ft_split("wc", ' ');
	//	msh.cmd->next->next->next->next  = malloc(sizeof(*msh.cmd_l) * 1);
	//	msh.cmd->next->next->next->next->arg = ft_split("wc -l", ' ');
	//	msh.cmd->next->next->next->next->next  = malloc(sizeof(*msh.cmd_l) * 1);
	//	msh.cmd->next->next->next->next->next->arg = ft_split("cat -e", ' ');
	//	msh.cmd->next->next->next->next->next->next = NULL;
	msh.envp_l = ms_clone_envp(envp);
	ms_cp_envp(&msh, envp);
	ms_redirects(&msh, &cmd);
	ms_pipex(&msh, &cmd);
	//	ms_command(&msh, msh.cmd);
	//	while(path[i++])
	//		printf("%s\n", path[i]);
	//	print_env_l(msh.envp_l);
	return (0);
}
