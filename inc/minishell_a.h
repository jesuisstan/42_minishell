// Artem's header

#ifndef MINISHELL_A_H
# define MINISHELL_A_H

# define MSH "minishell: "

char	*ms_find_envp(char **envp, char *key);
int		ms_arrlen(char **arr);

typedef struct s_msh
{
	char	**cp_envp;
}	t_msh;

#endif
