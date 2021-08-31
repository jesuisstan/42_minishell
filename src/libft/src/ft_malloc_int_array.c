/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_int_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:32:11 by acaren            #+#    #+#             */
/*   Updated: 2021/08/31 18:24:51 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// allocates memory for 2D rectangular array of integers

#include "../inc/libft.h"

int	**ft_malloc_int_array(int height, int width)
{
	int	i;
	int	**array_of_integers;

	array_of_integers = malloc(sizeof(int *) * (height + 1));
	if (!array_of_integers)
		return (NULL);
	i = 0;
	while (i < height)
	{
		array_of_integers[i] = malloc(sizeof(int) * (width));
		if (!array_of_integers[i])
			return (NULL);
		i++;
	}
	return (array_of_integers);
}
