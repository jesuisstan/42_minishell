/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:59:53 by acaren            #+#    #+#             */
/*   Updated: 2021/06/25 21:19:44 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// concat 2 str

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] && i < size)
		i++;
	j = 0;
	while (src[j])
	{
		if (j + i + 1 < size)
			dst[i + j] = src[j];
		j++;
	}
	if (size > i)
	{
		if (size - 1 < i + j)
			dst[size - 1] = '\0';
		else
			dst[i + j] = '\0';
	}
	return (i + j);
}
