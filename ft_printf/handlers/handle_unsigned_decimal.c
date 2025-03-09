#include "ft_printf.h"

int	handle_unsigned_decimal(unsigned int number)
{
	int	amount_digits;

	amount_digits = 0;
	if (number > 9)
		amount_digits += handle_unsigned_decimal((number / 10));
	amount_digits += handle_character((number % 10) + 48);
	return (amount_digits);
}
