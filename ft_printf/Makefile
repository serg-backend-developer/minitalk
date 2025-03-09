NAME 		= libftprintf.a
CC 			= cc
CC_FLAGS 	= -Wall -Werror -Wextra

LIBFT_SRC 	= ./libft
LIBFT 		= $(LIBFT_SRC)/libft.a

SRC 		= ft_printf.c \
			  handlers/handle_character.c \
			  handlers/handle_string.c \
			  handlers/handle_pointer.c \
			  handlers/handle_decimal.c \
			  handlers/handle_hexadecimal.c \
			  handlers/handle_unsigned_decimal.c
OBJS 		= $(SRC:.c=.o)

HEADER 		= ft_printf.h

# Rules
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_SRC) all

%.o: %.c  $(HEADER)
	$(CC) -c $(CC_FLAGS) -I ./ $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_SRC) clean

fclean: clean
	make -C $(LIBFT_SRC) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re