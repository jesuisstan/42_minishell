// Stas' header

#ifndef MINISHELL_S_H
# define MINISHELL_S_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_lst
{
	struct s_lst	*next;
	char			*val;
}			t_lst;

typedef struct s_msh
{
	int				old_in;
	int				old_out;
	int				prev_status;
	int				cur_status;
	char			*line;
	char			**envp_m;
	char			*name;
	struct s_envp	*envp_l;
	struct s_arg	*arg;
	struct s_cmd	*cmd_l;
	struct s_cmd	*lst_cmd; // мне это не нужно. Это дубликат t_cmd *cmd_l? Удалить может?
}			t_msh;

typedef struct s_cmd
{
	char			**cmd;
	t_lst			*lst_arg; // Это дублирование листа с командами? Удалить может?
	int				pipe_fd[2];
	int				in;
	int				out;
	pid_t			pid;
	int 			is_fork;
	struct s_cmd	*next;
}			t_cmd;

typedef struct s_arg
{
	char			*arg_rare;
	char			*arg_pure;
	struct s_arg	*next;
}			t_arg;

typedef struct s_envp
{
	char			*content;
	char			*key;
	char			*value;
	struct s_envp	*next;
}	t_envp;

t_envp	*ms_clone_envp(char **envp);
int		ms_check_redirect(char *line, int *index, char symbol);
int		ms_protoparse(char *line);
void	ms_parse(t_msh *msh, t_envp *envp_l, int g_status);
t_arg	*ms_split_line(t_msh *msh);
int		ms_pass_whitespaces(char *line);
char	*ms_clear_endwhitespaces(char *line);
char	*ms_manage_dollar(char *line, int *i, t_envp *envp_l, t_msh *msh);
char	*ms_purify_argument(char *arg_rare, t_msh *msh);
t_cmd	*ms_get_commands(t_msh *msh);

void	*ms_return_null(char *message);
int		ms_return_nbr(int return_value, char *message);
char	**ms_envplist_to_array(t_envp *envp_l);
char 	**ms_arglist_to_array(t_arg *arg, int size);
void	ms_lstclear_arg(t_arg **arg);
void	ms_lstclear_envp(t_envp **envp_l);
void	ms_lstclear_cmd(t_cmd **cmd_l);

#endif
