#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "ft_printf/ft_printf.h"

void	send_one_bit(int pid, int bit);
void	send_char_by_bits(int pid, unsigned char c);
void	send_str_by_char(int pid, const char *str);
void	handle_signal(int signum);
void	receive_and_handle_data(int signum, siginfo_t *info, void *context);

#endif
