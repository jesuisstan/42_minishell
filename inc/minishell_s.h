// Stas' header

#ifndef MINISHELL_S_H
# define MINISHELL_S_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_msh
{
	char			*line;
	struct s_envp	*envp_l;
	struct s_arg	*arg;
	int				flag_dollar;
}	t_msh;

typedef struct s_arg
{
	int				index;
	char			*arg_rare;
	char			*arg_pure;
	struct s_arg	*next;
}	t_arg;

typedef struct s_envp
{
	char			*content;
	char			*key;
	char			*value;
	struct s_envp	*next;
}	t_envp;

int		ms_pass_whitespaces(char *line);
int		ms_protoparse(char *line);
int		check_redirect(char *line, int *index, char symbol);
void	ms_parse(t_msh *mshell, char **envp);
t_envp	*ms_clone_envp(char **envp);
t_arg	*ms_split_line(char *line);
char	*ms_manage_dollar(char *line, int *i, t_msh *mshell);


void	*ms_return_null(char *message);
int		ms_return_nbr(int return_value, char *message);
int		ft_iswhitespace(int c);

#endif
