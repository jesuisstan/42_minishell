#include "../../inc/minishell.h"

static void	sig_noninter_quit(int sig)
{
	char	*nbr;

	nbr = ft_itoa(sig);
	ft_putstr_fd("Quit: ", STDERR_FILENO);
	ft_putendl_fd(nbr, STDERR_FILENO);
	g_status = 131;
	free(nbr);
	nbr = NULL;
}

static void	sig_noninter_ctrl_c(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", STDERR_FILENO);
	g_status = 130;
}

void	ms_signals_non_interactive_shell(void)
{
	signal(SIGTERM, SIG_DFL);
	signal(SIGINT, sig_noninter_ctrl_c);
	signal(SIGQUIT, sig_noninter_quit);
}
