/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 21:09:36 by acaren            #+#    #+#             */
/*   Updated: 2021/06/25 21:18:35 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clone n symbols of src to dst while src[] <> 'c'

#include "../inc/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(const unsigned char *)(src + i);
		if (*(const unsigned char *)(src + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
