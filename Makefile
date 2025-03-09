CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
SRC_PRINTF = ft_printf
SRC_CLIENT = client.c
SRC_SERVER = server.c
OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)
OBJ_SERVER = $(SRC_SERVER:%.c=%.o)
PRINTF = $(SRC_PRINTF)/libftprintf.a
LIB = -L$(SRC_PRINTF) -lftprintf
HEADERS = -I$(SRC_PRINTF)

# RULES
all: $(CLIENT) $(SERVER)

$(CLIENT): $(PRINTF) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(HEADERS) $(LIB) -o $(CLIENT)

$(SERVER): $(PRINTF) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(HEADERS) $(LIB) -o $(SERVER)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(PRINTF):
	$(MAKE) -C $(SRC_PRINTF)

clean:
	$(MAKE) -C $(SRC_PRINTF) clean
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER) 

fclean: clean
	$(MAKE) -C $(SRC_PRINTF) fclean
	rm -f $(CLIENT)
	rm -f $(SERVER)

re: fclean all

.PHONY: all clean fclean re