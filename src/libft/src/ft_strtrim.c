/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:07:18 by acaren            #+#    #+#             */
/*   Updated: 2021/06/25 21:20:13 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates and returns copy of ’s1’ trimmed by chars of ’set’ from both sides

#include "../inc/libft.h"

static int	ft_catch_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	a;
	size_t	z;

	if (!s1 || !set)
		return (NULL);
	a = 0;
	while (s1[a] && ft_catch_char(s1[a], set))
		a++;
	z = ft_strlen(s1);
	while (z > a && ft_catch_char(s1[z - 1], set))
		z--;
	str = (char *)malloc(sizeof(*s1) * (z - a + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (a < z)
		str[i++] = s1[a++];
	str[i] = 0;
	return (str);
}
