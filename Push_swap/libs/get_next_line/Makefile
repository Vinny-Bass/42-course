NAME = libgetnextline.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re