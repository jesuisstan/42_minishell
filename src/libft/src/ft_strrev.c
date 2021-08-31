/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:43:30 by acaren            #+#    #+#             */
/*   Updated: 2021/06/25 21:20:07 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reverse the string

#include "../inc/libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	temp;

	i = 0;
	size = 0;
	if (str)
	{
		while (str[size] != '\0')
		{
			size++;
		}
		while (i < size / 2)
		{
			temp = str[i];
			str[i] = str[size - i - 1];
			str[size - i - 1] = temp;
			++i;
		}
	}
	return (str);
}
