#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "./libft/libft.h"

int	handle_character(int c);
int	handle_decimal(int number);
int	handle_hexadecimal(unsigned int number, int case_flag);
int	handle_pointer(void *pointer);
int	handle_string(char *str);
int	handle_unsigned_decimal(unsigned int number);

int	ft_printf(const char *input, ...);

#endif
