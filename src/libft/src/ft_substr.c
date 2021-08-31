/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:39:22 by acaren            #+#    #+#             */
/*   Updated: 2021/06/25 21:20:20 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates and returns a substring of the string ’s’ from [start]

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = ft_calloc(1, sizeof(char));
		return (str);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
