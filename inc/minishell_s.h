// Stas' header

#ifndef MINISHELL_S_H
# define MINISHELL_S_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_arguments
{
	/* data */
	char			*line;
	struct s_envp	*envp_l;
}	t_arguments;

typedef struct s_envp
{
	char			*content;
	char			*key;
	char			*value;
	struct s_envp	*next;
}	t_envp;

int		ms_pass_whitespaces(char *line);
int		ms_protoparse(char *line);
void	ms_parse(t_arguments *arguments, char **envp);
t_envp	*ms_clone_envp(char **envp);
char	*ms_manage_dollar(char *line, int *i, t_envp *envp_l);

t_envp	*ft_lstlast(t_envp *lst);
void	ft_lstadd_back(t_envp **lst, t_envp *new);
void	*ms_return_null(char *message);
int		ms_return_nbr(int return_value, char *message);

#endif
