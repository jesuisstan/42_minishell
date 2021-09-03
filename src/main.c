/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:45:02 by acaren            #+#    #+#             */
/*   Updated: 2021/09/01 15:55:31 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	//hello
	int		n;
	int		m;
	char	**str;
	char	*string;
	
	m = argc;
	str = argv;
	
	n = ft_atoi(argv[1]);
	string = ms_malloc_x(sizeof(string) * n);
	(void)envp;
	// if (!(string = malloc(sizeof(char *) * n)))
	// 	return(ft_return_nbr(EXIT_FAILURE, strerror(errno)));
	free(string);
	return (0);
}
