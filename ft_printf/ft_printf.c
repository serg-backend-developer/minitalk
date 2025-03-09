#include "ft_printf.h"

static int	handle_input(const char *input, unsigned int *i, va_list *args)
{
	unsigned int	result;

	result = 0;
	if (input[*i] == 'c')
		result += handle_character(va_arg(*args, int));
	else if (input[*i] == 's')
		result += handle_string(va_arg(*args, char *));
	else if (input[*i] == 'p')
		result += handle_pointer(va_arg(*args, void *));
	else if (input[*i] == 'd' || input[*i] == 'i')
		result += handle_decimal(va_arg(*args, int));
	else if (input[*i] == 'u')
		result += handle_unsigned_decimal(va_arg(*args, int));
	else if (input[*i] == 'x')
		result += handle_hexadecimal(va_arg(*args, int), 1);
	else if (input[*i] == 'X')
		result += handle_hexadecimal(va_arg(*args, int), 0);
	else if (input[*i] == '%')
	{
		handle_character('%');
		return (1);
	}
	return (result);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			result += handle_input(input, &i, &args);
		}
		else
			result += handle_character(input[i]);
		i++;
	}
	va_end(args);
	return (result);
}
