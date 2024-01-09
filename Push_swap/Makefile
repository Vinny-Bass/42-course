NAME = main.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = list_utils.c main.c operations_utils.c operations.c utils.c handler.c
OBJS = $(SRCS:.c=.o)

LIBFT = ./libft
LIBFT_LIB = $(LIBFT)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT)
		cp $(LIBFT_LIB) $(NAME)
		$(CC) $(CFLAGS) $(OBJS) $(NAME) -o push_swap

bonus: $(OBJS)
		make -C $(LIBFT)
		cp $(LIBFT_LIB) $(NAME)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -rf $(NAME)


re: fclean all

.PHONY: all clean fclean re