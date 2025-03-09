#include "ft_printf.h"

static int	get_size_hexadecimal_address(unsigned long long number)
{
	int	size;

	size = 0;
	while (number)
	{
		size++;
		number /= 16;
	}
	return (size);
}

static int	get_hexadecimal_address(unsigned long long number)
{
	char	*hex_base;
	int		size;

	hex_base = "0123456789abcdef";
	size = get_size_hexadecimal_address(number);
	if (number < 16)
	{
		if (handle_character(hex_base[number]) == -1)
			return (-1);
	}
	else
	{
		get_hexadecimal_address(number / 16);
		get_hexadecimal_address(number % 16);
	}
	return (size);
}

int	handle_pointer(void *pointer)
{
	int	hex_str;

	if (handle_string("0x") == -1)
		return (-1);
	hex_str = get_hexadecimal_address((unsigned long long) pointer);
	if (hex_str != 0)
		return (hex_str + 2);
	else
		return (3);
}
