// Artem's header

#ifndef MINISHELL_A_H
# define MINISHELL_A_H

# define MSH "minishell: "

typedef struct s_lst
{
	char			*name;
	char			*val;
	struct s_lst	*next;
}			t_lst;

typedef struct s_msh
{
	char	**cp_envp;
	char	*path_oldpwd;
	t_lst	*env;
}			t_msh;

char	*ms_find_envp(char **envp, char *key);
int		ms_arrlen(char **arr);
void	ms_cp_envp(char **envp, t_msh *msh);


#endif
