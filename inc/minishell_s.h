/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_s.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:48:41 by acaren            #+#    #+#             */
/*   Updated: 2021/09/01 15:09:09 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Stas' header

#ifndef MINISHELL_S_H
# define MINISHELL_S_H

# include <stdio.h>

int		ms_print_envp(char **envp);
void	*ft_return_null(char *message);
int		ft_return_nbr(int return_value, char *message);

#endif
