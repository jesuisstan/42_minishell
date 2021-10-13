/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals_interactive_shell.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaren <acaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:36:28 by acaren            #+#    #+#             */
/*   Updated: 2021/10/13 21:18:31 by acaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ms_sig_inter_ctrl_c(int sig)
{
	(void)sig;
	write (STDERR_FILENO, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	g_status.exit = 1;
}

void	ms_signals_interactive_shell(void)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGINT, &ms_sig_inter_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
