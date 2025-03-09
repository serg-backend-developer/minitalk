#include "ft_printf.h"

static int	get_size_hexadecimal(unsigned int number)
{
	int	size;

	if (number == 0)
		size = 1;
	else
		size = 0;
	while (number)
	{
		size++;
		number /= 16;
	}
	return (size);
}

int	handle_hexadecimal(unsigned int number, int case_flag)
{
	char			*hex_base;
	int				size;

	size = get_size_hexadecimal(number);
	hex_base = "0123456789abcdef";
	if (case_flag == 0)
		hex_base = "0123456789ABCDEF";
	if (number < 16)
	{
		if (handle_character(hex_base[number]) == -1)
			return (-1);
	}
	else
	{
		if (handle_hexadecimal(number / 16, case_flag) == -1)
			return (-1);
		if (handle_hexadecimal(number % 16, case_flag) == -1)
			return (-1);
	}
	return (size);
}
