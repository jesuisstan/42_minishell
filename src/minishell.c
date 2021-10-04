//
// Created by Melinda Shmelly on 10/4/21.
//

//#include "../inc/minishell.h"
//
//int	main(int argc, char **argv, char **envp)
//{
//	int		i;
//	t_msh	*msh;
//	char	**res;
//
//	msh = ms_malloc_x(sizeof(t_msh));
//	rl_outstream = stderr;
//	while (1)
//	{
//		ms_parse(msh, envp);
//		printf("line XXX = %s\n", msh->line);
//		while (msh->arg) //todo распечатывает связ. список с аргументами line
//			{
//			printf("arg rare = %s\n", msh->arg->arg_rare);
//			printf("arg pure = %s\n", msh->arg->arg_pure);
//			printf("\n");
//			msh->arg = msh->arg->next;
//			}
//	}
//	return (0);
//}