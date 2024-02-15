NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	src/operations/operations_utils.c \
		src/operations/operations.c \
		src/sorting/simple_sort.c \
		src/sorting/complex_sort.c \
		src/utils/main_utils.c \
		src/utils/list_utils.c \
		src/utils/arr_utils.c \
		src/utils/memory_utils.c \
		src/utils/utils.c \
		src/errors/errors.c \
		src/main.c
OBJS = $(SRCS:.c=.o)

LIBFT = ./libs/libft
LIBFT_LIB = $(LIBFT)/libft.a
FT_PRINT_F = ./libs/ft_printf
FT_PRINT_F_LIB = $(FT_PRINT_F)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT)
		make -C $(FT_PRINT_F)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(FT_PRINT_F_LIB)

bonus: $(OBJS)
		make -C $(LIBFT)
		cp $(LIBFT_LIB) $(NAME)
		ar rcs $(NAME) $(OBJS)

clean:
		make clean -C $(LIBFT)
		make clean -C $(FT_PRINT_F)
		rm -f $(OBJS)

fclean: clean
		make fclean -C $(LIBFT)
		make fclean -C $(FT_PRINT_F)
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re