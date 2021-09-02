/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_return_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:53:27 by acaren            #+#    #+#             */
/*   Updated: 2021/09/01 14:50:51 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// prints in STD_ERROR error's description ("message") & returns "return_value"

#include "../inc/minishell.h"

void	*ms_return_null(char *message)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, message, ft_strlen(message));
	write(STDERR_FILENO, "\n", 1);
	return (NULL);
}

int	ms_return_nbr(int return_value, char *message)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, message, ft_strlen(message));
	write(STDERR_FILENO, "\n", 1);
	return (return_value);
}
