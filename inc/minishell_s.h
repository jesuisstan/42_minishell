// Stas' header

#ifndef MINISHELL_S_H
# define MINISHELL_S_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_msh
{
	char			*line;
	char			**envp_m;
	struct s_envp	*envp_l;
	struct s_arg	*arg;
	struct s_cmd	*cmd_l;
	int				last_exit_status; // это результат вып-ия последней команды. Нужен для $?
}	t_msh;

typedef struct s_arg
{
	char			*arg_rare;
	char			*arg_pure;
	struct s_arg	*next;
}	t_arg;

typedef struct s_cmd
{
	char			**cmd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_envp
{
	char			*content;
	char			*key;
	char			*value;
	struct s_envp	*next;
}	t_envp;

int		ms_pass_whitespaces(char *line);
int		ms_protoparse(char *line);
int		ms_check_redirect(char *line, int *index, char symbol);
void	ms_parse(t_msh *g_msh, t_envp *envp_l);
t_envp	*ms_clone_envp(char **envp);
void	ms_cut_arguments(char *line, t_arg **arg, t_msh *g_msh);
t_arg	*ms_lstnew_arg(char *content, t_msh *g_msh);
char	*ms_manage_dollar(char *line, int *i, t_envp *envp_l, t_msh *g_msh);
char	*ms_purify_argument(char *arg_rare, t_msh *g_msh);

t_cmd	*ms_get_commands(t_arg *arg);

void	*ms_return_null(char *message);
int		ms_return_nbr(int return_value, char *message);
int		ft_iswhitespace(int c);
char	**ms_envplist_to_array(t_envp *envp_l);
char 	**ms_arglist_to_array(t_arg *arg, int size);
void	ms_lstclear_arg(t_arg **arg);
void	ms_lstclear_envp(t_envp **envp_l);

#endif
