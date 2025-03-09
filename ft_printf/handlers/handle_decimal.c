#include "ft_printf.h"

int	handle_decimal(int number)
{
	int	amount_digits;

	amount_digits = 0;
	if (number == INT_MIN)
		return (handle_string("-2147483648"));
	else if (number < 0)
	{
		amount_digits += handle_character('-');
		number *= -1;
	}
	if (number > 9)
		amount_digits += handle_decimal(number / 10);
	amount_digits += handle_character((number % 10) + 48);
	return (amount_digits);
}
