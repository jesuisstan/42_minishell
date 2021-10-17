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

//utils
void	*ms_malloc_x(size_t size);
int		ms_arrlen(char **arr);
t_envp	*lstnew_envp(char *content);
void	lstadd_back_envp(t_envp **envp_l, t_envp *new);
char	*ms_find_envp_l(t_envp **lst, char *key);
void	ms_find_envp_l_and_replace_val(t_envp **envp_l, char *key, char *val);
char	*get_key(char *content);
char	*get_value(char *content);
size_t	ms_lstsize(t_cmd *arg);

//commands
void	ms_builtins(t_msh *msh, t_cmd *cmd);
int		is_builtins(char *key);
void	ms_command(t_msh *msh, t_cmd *cmd);
int		ms_dups(t_cmd *cmd);
int		ms_error(char *str);
int		ms_not_pipe(t_cmd *start);
int		is_path(char *name);
char	*done_path(t_msh *msh, char *name);
int		ms_pipex(t_msh *msh, t_cmd *cmd, int len_cmd);
int		ms_redirects(t_cmd *cmd);

//builtins
int		ms_cd(t_msh *msh, char **argv);
int		ms_cd_oldpwd(t_msh *msh);
int		ms_change_dir(t_msh *msh, char *path);
int		ms_new_pwd(t_msh *msh);
int		ms_echo(char **arr);
int		ms_env(t_envp *lst);
int		ms_exit(t_msh *msh, char **argv);
int		ms_pwd(void);
int		ms_unset(t_msh *msh, char **argv);
int		ms_export(t_msh *msh, char **argv);
int		print_env_l(t_envp *lst);
int		is_key_exist(t_envp **env, char *key);






#endif