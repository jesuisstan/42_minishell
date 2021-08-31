/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:37:38 by acaren            #+#    #+#             */
/*   Updated: 2021/06/25 21:18:38 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns 1st occurence of 'c' in *s on n-distance

#include "../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(const unsigned char *)(s + i) != (const unsigned char)c)
			i++;
		else
			return ((void *)(s + i));
	}
	return (NULL);
}
