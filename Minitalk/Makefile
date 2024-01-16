NAME = main.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

FT_PRINT_F_DIR = ./ft_printf
FT_PRINT_F = $(FT_PRINT_F_DIR)/libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: server client

server: $(SERVER_OBJS)
	make -C $(FT_PRINT_F_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -L$(FT_PRINT_F_DIR) -lftprintf -L$(LIBFT_DIR) -lft -o server

client: $(CLIENT_OBJS)
	make -C $(FT_PRINT_F_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -L$(FT_PRINT_F_DIR) -L$(LIBFT_DIR) -lftprintf -lft -o client

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) client server
	make fclean -C $(FT_PRINT_F_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(FT_PRINT_F_DIR)

re: fclean all

.PHONY: all server client clean fclean re