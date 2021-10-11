// gcc ms_signals.c ../utils/*.c ../parser/*.c ../libft/libft.a -lreadline -o signals
#include "../../inc/minishell.h"

void	ms_sig_int(int code)
{
	(void)code;
	if (g_sig.pid == 0)
	{
	printf("piddd = %d", g_sig.pid);
		ft_putstr_fd("\n", STDERR_FILENO);
		ft_putstr_fd("minishell $ ", STDERR_FILENO);
		g_sig.exit_status = 1;
	}
	else
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		g_sig.exit_status = 130;
	}
//	g_sig.sig_int = 1;
}

void	ms_sig_quit(int code)
{
	char	*nbr;

	nbr = ft_itoa(code);
	if (g_sig.pid != 0)
	{
printf("piddd = %d", g_sig.pid);
		ft_putstr_fd("YO-YO Quit: ", STDERR_FILENO);
		ft_putendl_fd(nbr, STDERR_FILENO);
		g_sig.exit_status = 131;
//		g_sig.sig_quit = 1;
	}
	else
		ft_putstr_fd("\b\b  \b\b", STDERR_FILENO);
	free (nbr);
	nbr = NULL;
}
