/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_print_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:19:39 by acaren            #+#    #+#             */
/*   Updated: 2021/08/31 18:31:06 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc *.c ./libft/libft.a -o minishell

#include "../inc/minishell.h"

int	ms_print_envp(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		ft_putstr_fd(envp[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	return (0);
}
