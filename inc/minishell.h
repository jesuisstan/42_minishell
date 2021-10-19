/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshmelly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:59:50 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/17 18:59:54 by mshmelly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MSH "minishell: "
# define RDR_L1		0
# define RDR_L2		1
# define RDR_R1		3
# define RDR_R2		4

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <sys/errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../src/libft/inc/libft.h"

# include "./minishell_struct.h"

//utils
void	*ms_malloc_x(size_t size);
int		ms_arrlen(char **arr);
char	*get_key(char *content);
char	*get_value(char *content);
void	ms_shlvl_up(t_msh *msh);
void	ms_shlvl_down(t_msh *msh);
void	*ms_return_null(char *message);
int		ms_return_nbr(int return_value, char *message);
char	**ms_arglist_to_array(t_arg *arg, int size);
size_t	ms_lstsize(t_cmd *arg);
void	ms_lstfree_arg(t_arg **arg);
void	lstdelone_arg(t_arg *arg);
void	ms_lstfree_cmd(t_cmd **cmd_l);
void	ms_lstfree_rdr(t_rdr **rdr);
t_envp	*lstnew_envp(char *content);
char	**ms_envplist_to_array(t_envp *envp_l);
char	*ms_find_envp_l(t_envp **lst, char *key);
void	lstadd_back_envp(t_envp **envp_l, t_envp *new);
void	ms_find_envp_l_and_replace_val(t_envp **envp_l, char *key, char *val);

//commands
void	ms_builtins(t_msh *msh, t_cmd *cmd);
void	ms_command(t_msh *msh, t_cmd *cmd);
char	*done_path(t_msh *msh, char *name);
int		is_builtins(char *key);
int		ms_dups(t_cmd *cmd);
int		ms_error(char *str);
int		ms_not_pipe(t_cmd *start);
int		is_path(char *name);
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

//parser
int		ms_protoparse(char *line);
int		ms_check_redirect(char *line, int *index, char symbol);
int		ms_pass_whitespaces(char *line);
int		ms_isredirect(char *str);
char	*ms_clear_endwhitespaces(char *line);
char	*ms_manage_dollar(char *line, int *i, t_envp *envp_l);
char	*ms_handle_digital_key(char *line, char *key, int j, int *i);
char	*ms_purify_argument(char *arg_rare, t_msh *msh);
void	ms_set_redirect_flags(t_arg **arg);
void	ms_parse(t_msh *msh, t_envp *envp_l);
void	ms_signals_interactive_shell(void);
void	ms_signals_non_interactive_shell(void);
t_rdr	*ms_extract_redirects(t_arg **arg);
t_arg	*ms_split_line(t_msh *msh);
t_cmd	*ms_get_commands(t_msh *msh);
t_envp	*ms_clone_envp(char **envp);

#endif
