#include "ft_printf.h"

int	handle_character(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
