/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshmelly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:18 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/17 18:58:18 by mshmelly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	handle_left(char *str, int i, int spaces_passed, int *index)
{
	if (spaces_passed == 0)
	{
		if (str[i] == '\0' || str[i] == '|' || str[i] == '>')
			return (EXIT_FAILURE);
		if (str[i] == '<')
		{
			i++;
			i += ms_pass_whitespaces(&str[i]);
			*index += i;
			if (str[i] == '<' || str[i] == '\0' || str[i] == '|'
				|| str[i] == '>')
				return (EXIT_FAILURE);
		}
	}
	else
	{
		*index += spaces_passed;
		if (str[i] == '<' || str[i] == '\0' || str[i] == '|' || str[i] == '>')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	handle_right(char *str, int i, int spaces_passed, int *index)
{
	if (spaces_passed == 0)
	{
		if (str[i] == '<' || str[i] == '\0' || str[i] == '|')
			return (EXIT_FAILURE);
		if (str[i] == '>')
		{
			i++;
			i += ms_pass_whitespaces(&str[i]);
			*index += i;
			if (str[i] == '<' || str[i] == '\0' || str[i] == '|'
				|| str[i] == '>')
				return (EXIT_FAILURE);
		}
	}
	else
	{
		*index += spaces_passed;
		if (str[i] == '<' || str[i] == '\0' || str[i] == '|' || str[i] == '>')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ms_check_redirect(char *line, int *index, char symbol)
{
	int		i;
	int		n;
	char	*str;

	str = &line[++(*index)];
	i = 0;
	n = ms_pass_whitespaces(str);
	i += n;
	if (symbol == '>' && handle_right(str, i, n, index))
	{
		g_status = 258;
		return (ms_return_nbr(1, "syntax error near unexpected token `>'"));
	}
	if (symbol == '<' && handle_left(str, i, n, index))
	{
		g_status = 258;
		return (ms_return_nbr(1, "syntax error near unexpected token `<'"));
	}
	return (EXIT_SUCCESS);
}
