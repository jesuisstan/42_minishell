/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 00:22:40 by acaren            #+#    #+#             */
/*   Updated: 2021/06/25 21:19:36 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// locates the first occurrence of 'c' in the string pointed to by 'str'

#include "../inc/libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}
