/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 00:22:40 by acaren            #+#    #+#             */
/*   Updated: 2021/08/23 22:23:25 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	nbr;

	sign = 1;
	nbr = 0;
	if (str == NULL)
		return (0);
	while ((*str == '\n') || (*str == '\t') || (*str == '\v')
		|| (*str == ' ') || (*str == '\r') || (*str == '\f'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (int)(*str - '0');
		str++;
		if ((sign == -1) && (nbr > 9223372036854775808u))
			return (0);
		if ((sign == 1) && (nbr >= 9223372036854775808u))
			return (-1);
	}
	return (sign * nbr);
}
