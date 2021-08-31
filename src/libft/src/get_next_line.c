/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:01:01 by acaren            #+#    #+#             */
/*   Updated: 2021/06/27 01:29:33 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*ft_check_tail_n(char *tail, char **line)
{
	char		*n_pointer;

	n_pointer = NULL;
	if (tail)
	{
		n_pointer = ft_strchr(tail, '\n');
		if (ft_strchr(tail, '\n'))
		{
			*n_pointer = '\0';
			*line = ft_strdup(tail);
			n_pointer++;
			ft_memcpy(tail, n_pointer, ft_strlen(n_pointer));
			tail[ft_strlen(n_pointer)] = '\0';
		}
		else
		{
			*line = ft_strdup(tail);
			free (tail);
			tail = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (n_pointer);
}

static char	*ft_check_buff_n(char **buff,
	char *n_pointer, char **tail, char **line)
{
	char	*tmp;

	n_pointer = ft_strchr(*buff, '\n');
	if (n_pointer)
	{
		*n_pointer = '\0';
		n_pointer++;
		*tail = ft_strdup(n_pointer);
	}
	tmp = *line;
	*line = ft_strjoin(*line, *buff);
	free (tmp);
	tmp = NULL;
	return (n_pointer);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	char		*n_pointer;
	int			red;
	static char	*tail;

	if (BUFFER_SIZE < 1 || !line || fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	n_pointer = ft_check_tail_n(tail, line);
	red = 1;
	while (!n_pointer && red)
	{
		red = read(fd, buff, BUFFER_SIZE);
		buff[red] = '\0';
		n_pointer = ft_check_buff_n(&buff, n_pointer, &tail, line);
	}
	free (buff);
	if (red == 0)
	{
		tail = NULL;
		return (0);
	}
	return (1);
}
