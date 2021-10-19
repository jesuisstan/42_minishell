/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:00:11 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/19 18:30:50 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

# include <stdlib.h>

int				g_status;

typedef struct s_msh
{
	char			*line;
	char			**envp_m;
	char			*name;
	struct s_envp	*envp_l;
	struct s_arg	*arg;
	struct s_cmd	*cmd_l;
}				t_msh;

typedef struct s_cmd
{
	char			**cmd;
	int				pipe_fd[2];
	int				in;
	int				out;
	int				is_fork;
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
	int				flag_isredirect;
	struct s_arg	*next;
}				t_arg;

typedef struct s_envp
{
	char			*content;
	char			*key;
	char			*value;
	struct s_envp	*next;
}				t_envp;

#endif
