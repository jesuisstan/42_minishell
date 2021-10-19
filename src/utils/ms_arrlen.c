/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshmelly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:18 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/17 18:58:18 by mshmelly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
**	@brief		funtion count the lenght array
**
**	@param		envp and key
**	@return		the contents of the key in the environment
*/

int	ms_arrlen(char **arr)
{
	int	len;

	len = 0;
	if (arr == NULL)
		return (0);
	while (arr[len])
		len++;
	return (len);
}

size_t	ms_lstsize(t_cmd *arg)
{
	size_t	i;

	if (!arg)
		return (0);
	i = 0;
	while (arg)
	{
		arg = arg->next;
		i++;
	}
	return (i);
}
