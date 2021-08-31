/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:43:30 by acaren            #+#    #+#             */
/*   Updated: 2021/07/01 16:57:42 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates and returns an array of strings by splitting ’*s’ with ’c’

#include "../inc/libft.h"

static int	ft_count_str(char const *s, char c)
{
	size_t	i;
	int		counter;
	int		n;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		n = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			n = 1;
			i++;
		}
		if (n == 1)
			counter++;
	}
	return (counter);
}

static char	*ft_copy(const char *str, int len)
{
	char	*cpy;

	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	cpy = ft_memcpy(cpy, str, len);
	cpy[len] = '\0';
	return (cpy);
}

static char	**ft_zero_array(char **res, int i)
{
	while (i--)
	{
		free (res[i]);
		res[i] = NULL;
	}
	free (res);
	res = NULL;
	return (res);
}

static int	ft_find_begin(char const *s, char c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		begin;
	int		end;
	char	**res;
	size_t	i;

	end = 0;
	i = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_count_str(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[end])
	{
		end = ft_find_begin(s, c, end);
		begin = end;
		while (s[end] && s[end] != c)
			end++;
		if (end > begin)
			res[i++] = ft_copy(s + begin, end - begin);
		if (end > begin && !res[i - 1])
			return (ft_zero_array(res, i - 1));
	}
	res[i] = NULL;
	return (res);
}
