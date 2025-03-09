#include "ft_printf.h"

int	handle_string(char *str)
{
	unsigned int	amount_chars_in_str;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	amount_chars_in_str = ft_strlen(str);
	return (amount_chars_in_str);
}
