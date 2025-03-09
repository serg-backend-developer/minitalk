#include "minitalk.h"

void	receive_and_handle_data(
	int signal,
	siginfo_t *signal_data,
	void *context
)
{
	static unsigned char	c = 0;
	static int				amount_bits = 0;
	static pid_t			pid_client = 0;

	(void)context;
	if (pid_client != signal_data->si_pid)
	{
		amount_bits = 0;
		c = 0;
		write(1, "\n", 1);
	}
	pid_client = signal_data->si_pid;
	c = c << 1;
	if (signal == SIGUSR1)
		c = c | 1;
	amount_bits++;
	if (amount_bits == 8)
	{
		write(1, &c, 1);
		amount_bits = 0;
		c = 0;
	}
	kill(pid_client, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server process [PID]: %d\n", getpid());
	sa.sa_sigaction = &receive_and_handle_data;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
