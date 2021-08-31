/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:48:56 by acaren            #+#    #+#             */
/*   Updated: 2021/06/25 21:19:16 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr_uns_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_uns_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
