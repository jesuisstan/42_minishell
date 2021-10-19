/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshmelly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:17 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/17 18:58:17 by mshmelly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ms_error(char *str)
{
	if (str)
		ft_putendl_fd(str, STDERR_FILENO);
	else
		perror("Error");
	g_status = 128;
	return (1);
}

int	ms_not_pipe(t_cmd *start)
{
	ft_putstr_fd(MSH, STDERR_FILENO);
	ft_putendl_fd("fork: Resource temporarily unavailable", STDERR_FILENO);
	g_status = 128;
	(void)start;
	while (start->next)
	{
		if (!start->pipe_fd[0] || !start->pipe_fd[1])
			break ;
		close(start->pipe_fd[0]);
		close(start->pipe_fd[1]);
		start = start->next;
	}
	return (1);
}
