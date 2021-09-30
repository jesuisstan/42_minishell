#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <fcntl.h>
# include "../src/libft/inc/libft.h"

# include "./minishell_a.h"
# include "./minishell_s.h"

void	*ms_malloc_x(size_t size);
char	*ms_find_envp_l(t_envp **lst, char *key);
char	*ms_find_envp_m(char **envp, char *key);
int	ms_find_envp_m_and_replace_val(char **envp, char *key, char *val);

void	ms_cp_envp(t_msh *msh, char **envp);
int		ms_arrlen(char **arr);
t_envp	*lstnew_envp(char *content);
void	lstadd_back_envp(t_envp **lst, t_envp *new);
void	print_env_l(t_envp *lst);
int		gen_next_path(char **argv, char **paths, char *name);
void	run_command(t_msh *msh, t_cmd *cmd);



//cd
int	ms_cd(t_msh *msh, char **argv);

void	ms_oldpwd(t_msh *msh, char *oldpwd);
int		ms_new_pwd(t_msh *msh);


#endif
