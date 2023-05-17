/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_manage_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: St.Krivtsov <stan.krivtsov@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:58:18 by mshmelly          #+#    #+#             */
/*   Updated: 2023/05/17 20:05:31 by St.Krivtsov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern int g_status;

static char	*handle_char_key(char *line, char *value, int j, int *i)
{
	char	*line_new;
	char	*tmp_one;
	char	*tmp_two;
	void	*tmp_three;

	if (!value)
	{
		tmp_one = ft_substr(line, 0, j);
		tmp_two = ft_strdup(&line[*i]);
		line_new = ft_strjoin(tmp_one, tmp_two);
		*i = j - 1;
	}
	else
	{
		tmp_one = ft_substr(line, 0, j);
		tmp_two = ft_strjoin(tmp_one, value);
		tmp_three = (char *)ft_strdup(&line[*i]);
		line_new = ft_strjoin(tmp_two, tmp_three);
		*i = j + ft_strlen(value) - 1;
		free(tmp_three);
	}
	free(tmp_one);
	free(tmp_two);
	free(line);
	return (line_new);
}

static int	if_key(char c)
{
	if (c == '_' || ft_isalnum(c) || c == '*' || c == '!')
		return (1);
	return (0);
}

static char	*handle_question_mark(char *line, int j, int *i)
{
	char	*line_new;
	char	*tmp_one;
	char	*tmp_two;
	char	*nbr_val;
	char	*tail;

	nbr_val = ft_itoa(g_status);
	tmp_one = ft_substr(line, 0, j);
	tmp_two = ft_strjoin(tmp_one, nbr_val);
	tail = ft_strdup(&line[*i]);
	line_new = ft_strjoin(tmp_two, tail);
	free(nbr_val);
	free(tmp_one);
	free(tmp_two);
	free(tail);
	free(line);
	g_status = 0;
	return (line_new);
}

char	*ms_manage_dollar(char *line, int *i, t_envp *envp_l)
{
	int		j;
	char	*key;
	char	*value;
	char	*line_new;

	j = *i;
	if (ft_strchr("?", line[j + 1]))
	{
		*i += 2;
		return (handle_question_mark(line, j, i));
	}
	while (line[++(*i)])
		if (!if_key(line[*i]))
			break ;
	if (*i == j + 1)
		return (line);
	key = ft_substr(line, j + 1, *i - j - 1);
	if (ft_isdigit(key[0]))
		return (ms_handle_digital_key(line, key, j, i));
	else
		value = ms_find_envp_l(&envp_l, key);
	line_new = handle_char_key(line, value, j, i);
	free(key);
	return (line_new);
}
