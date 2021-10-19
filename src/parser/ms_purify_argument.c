/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_purify_argument.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshmelly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:18 by mshmelly          #+#    #+#             */
/*   Updated: 2021/10/17 18:58:18 by mshmelly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*manage_quotes(char *line, int *i, t_msh *msh)
{
	int		j;
	char	*line_new;
	char	*tmp_one;
	char	*tmp_two;
	char	*tmp_three;

	(void)msh;
	j = *i;
	while (line[++(*i)])
		if (line[*i] == '\"')
			break ;
	tmp_one = ft_substr(line, 0, j);
	tmp_two = ft_substr(line, j + 1, *i - j - 1);
	tmp_three = ft_strjoin(tmp_one, tmp_two);
	free(tmp_one);
	tmp_one = ft_strdup(&line[*i + 1]);
	line_new = ft_strjoin(tmp_three, tmp_one);
	*i -= 2;
	free(tmp_one);
	free(tmp_two);
	free(tmp_three);
	free(line);
	return (line_new);
}

static char	*manage_apostrophe(char *line, int *i)
{
	int		j;
	char	*line_new;
	char	*tmp_one;
	char	*tmp_two;
	char	*tmp_three;

	j = *i;
	while (line[++(*i)])
		if (line[*i] == '\'')
			break ;
	tmp_one = ft_substr(line, 0, j);
	tmp_two = ft_substr(line, j + 1, *i - j - 1);
	tmp_three = ft_strjoin(tmp_one, tmp_two);
	free(tmp_one);
	tmp_one = ft_strdup(&line[*i + 1]);
	line_new = ft_strjoin(tmp_three, tmp_one);
	*i -= 2;
	free(tmp_one);
	free(tmp_two);
	free(tmp_three);
	free(line);
	return (line_new);
}

static char	*make_new_str(char *str, int size)
{
	char	*str_new;

	str_new = ft_substr(str, 0, size);
	free(str);
	str = NULL;
	return (str_new);
}

static char	*ms_kill_blanc(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\"')
		{
			++i;
			while (str[i] != '\"' && str[i])
				i++;
		}
		else if (str[i] == '\'')
		{
			++i;
			while (str[i] != '\'' && str[i])
				i++;
		}
		else if (ft_strchr(" \t", str[i]))
			return (make_new_str(str, i));
	}
	return (str);
}

char	*ms_purify_argument(char *arg, t_msh *msh)
{
	int		i;
	char	*arg_pure;

	arg += ms_pass_whitespaces(arg);
	arg = ms_kill_blanc(arg);
	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '\'')
		{
			arg = manage_apostrophe(arg, &i);
			arg_pure = arg;
		}
		else if (arg[i] == '\"')
		{
			arg = manage_quotes(arg, &i, msh);
			arg_pure = arg;
		}
		else
			arg_pure = arg;
	}
	return (arg_pure);
}
