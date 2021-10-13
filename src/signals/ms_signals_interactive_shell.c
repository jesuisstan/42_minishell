#include "../../inc/minishell.h"

void	ms_sig_inter_ctrl_c(int sig)
{
	(void)sig;
	ft_putendl_fd("minishell $   ", STDERR_FILENO);
//	rl_replace_line("", 0); данная функция мешает мне пользоваться дебагером силайна
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
