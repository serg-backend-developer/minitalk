#include "minitalk.h"

int	g_sync_signal_flag = 0;

void	handle_g_sync_signal_flag(int signal)
{
	g_sync_signal_flag = 1;
	(void)signal;
}

void	send_one_bit(int pid, int bit)
{
	int	signal;

	if (bit == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(pid, signal) == -1)
	{
		ft_putstr_fd("Error!", 2);
		exit(EXIT_FAILURE);
	}
	while (!g_sync_signal_flag)
		;
	g_sync_signal_flag = 0;
}

void	send_char_by_bits(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_one_bit(pid, (c >> i) & 1);
		usleep(400);
		i--;
	}
}

void	send_str_by_char(int pid, const char *str)
{
	while (*str)
		send_char_by_bits(pid, *str++);
	send_char_by_bits(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Not correct input. Correct: ./client [PID] [STRING]\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Invalid [PID]!\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR2, handle_g_sync_signal_flag);
	send_str_by_char(pid, argv[2]);
	return (0);
}
