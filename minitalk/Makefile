CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

LIBFT_DIR = libft
LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

PRINTF_DIR = printf
PRINTF_SRC = $(wildcard $(PRINTF_DIR)/*.c)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

all: client server

client: $(CLIENT_OBJ) libft.a libftprintf.a
	$(CC) $(CFLAGS) -o $@ $^

server: $(SERVER_OBJ) libft.a libftprintf.a
	$(CC) $(CFLAGS) -o $@ $^

libft.a: $(LIBFT_OBJ)
	ar rc $@ $^
	ranlib $@

libftprintf.a: $(PRINTF_OBJ)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ)

fclean: clean
	@echo "$(RED)Force cleaning$(NC)"
	rm -f client server libft.a libftprintf.a

re: fclean all
	@echo "$(GREEN)Rebuild complete$(NC)"

.PHONY: all clean fclean re
