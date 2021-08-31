/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 00:22:40 by acaren            #+#    #+#             */
/*   Updated: 2021/06/25 21:18:49 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (n--)
			*(unsigned char *)(dst + n) = *(unsigned char *)(src + n);
	}
	else
		ft_memcpy(dst, src, n);
	return (str);
}
