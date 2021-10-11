#ifndef MINISHELL_S_H
# define MINISHELL_S_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

typedef struct s_lst
{
	struct s_lst	*next;
	char			*val;
}				t_lst;

typedef struct s_msh
{
	int				old_in;
	int				old_out;
	//int				prev_status;
	//int				cur_status;
	//int				sigint;
	//int				sigquit;
	char			*line;
	char			**envp_m;
	char			*name;
	struct s_envp	*envp_l;
	struct s_arg	*arg;
	struct s_cmd	*cmd_l;
}				t_msh;

typedef struct	s_signal
{
	int				exit_status;
	pid_t			pid;
}				t_signal;

typedef struct s_cmd
{
	char			**cmd;
	int				pipe_fd[2];
	int				in;
	int				out;
	int 			is_fork;
	pid_t			pid;
	struct s_rdr	*rdr;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_rdr
{
	char			*name;
	struct s_rdr	*next;
}				t_rdr;

typedef struct s_arg
{
	char			*arg_rare;
	char			*arg_pure;
	struct s_arg	*next;
}				t_arg;

typedef struct s_envp
{
	char			*content;
	char			*key;
	char			*value;
	struct s_envp	*next;
}				t_envp;

t_signal	g_sig;

void	ms_shlvl_up(t_msh *msh);
void	ms_shlvl_down(t_msh *msh);
t_envp	*ms_clone_envp(char **envp);
int		ms_check_redirect(char *line, int *index, char symbol);
int		ms_protoparse(char *line);
void	ms_parse(t_msh *msh, t_envp *envp_l);
t_arg	*ms_split_line(t_msh *msh);
int		ms_pass_whitespaces(char *line);
char	*ms_clear_endwhitespaces(char *line);
char	*ms_manage_dollar(char *line, int *i, t_envp *envp_l);
char	*ms_purify_argument(char *arg_rare, t_msh *msh);
t_cmd	*ms_get_commands(t_msh *msh);
t_rdr	*ms_extract_redirects(t_arg **arg);
int		ms_isredirect(char *str);
void	ms_sig_quit(int code);
void	ms_sig_int(int code);

void	*ms_return_null(char *message);
int		ms_return_nbr(int return_value, char *message);
char	**ms_envplist_to_array(t_envp *envp_l);
char 	**ms_arglist_to_array(t_arg *arg, int size);
void	ms_lstfree_arg(t_arg **arg);
void	lstdelone_arg(t_arg *arg);
void	ms_lstfree_cmd(t_cmd **cmd_l);

#endif
