#ifndef MINISHELL_H
# define MINISHELL_H
# define MSH "minishell: "
# define RDR_L1		0
# define RDR_L2		1
# define RDR_R1		3
# define RDR_R2		4

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <fcntl.h>
# include "../src/libft/inc/libft.h"

# include "./minishell_a.h"
# include "./minishell_s.h"

int g_status;


void	*ms_malloc_x(size_t size);
int		ms_arrlen(char **arr);
int		gen_next_path(char **argv, char **paths, char *name);
void	ms_command(t_msh *msh, t_cmd *cmd);
char	**get_path(t_msh *msh);
int		ms_pipex(t_msh *msh, t_cmd *cmd);
int		is_builtins(char *key);

t_envp	*lstnew_envp(char *content);
void	lstadd_back_envp(t_envp **envp_l, t_envp *new);
void	lstadd_front_envp(t_envp **envp_l, t_envp *new);
void	lstremove_node_envp(t_envp **envp_l, char *key);
void	lstfree_envp(t_envp **envp_l);
char	*ms_find_envp_l(t_envp **lst, char *key);
char	*ms_find_envp_m(char **envp, char *key);
int		ms_find_envp_m_and_replace_val(char **envp, char *key, char *val);
int		ms_find_envp_l_and_replace_val(t_envp **envp_l, char *key, char *val);
void	print_env_l(t_envp *lst);
void	ms_cp_envp(t_msh *msh, char **envp);
int	ms_redirects(t_cmd *cmd);
char	*get_key(char *content);
char	*get_value(char *content);
int	ms_in_out(t_msh *msh, t_cmd *cmd);

//cd
int		ms_cd(t_msh *msh, char **argv);
void	ms_oldpwd(t_msh *msh, char *oldpwd);
int		ms_new_pwd(t_msh *msh);

//echo
int		ms_echo(char **arr);

// env
int		ms_env(t_envp *lst);

//exit
int		ms_exit(char **argv);

//pwd
int		ms_pwd(void);

//unset
int		ms_unset(t_msh *msh, char **argv);

//export
int		ms_export(t_msh *msh, char **argv);

void	ms_builtins(t_msh *msh, t_cmd *cmd);

#endif