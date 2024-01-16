NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = digit_flags.c digit_handlers.c digit_utils.c flags_handler.c format_handler.c ft_printf.c text_handlers.c utils.c
OBJS = $(SRCS:.c=.o)

LIBFT = ../libft
LIBFT_LIB = $(LIBFT)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
