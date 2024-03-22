NAME = philo
CC = gcc
CFLAGS = -g -Werror -Wall -Wextra

SRCS =	src/arguments.c \
		src/dinner_actions.c \
		src/dinner.c \
		src/errors.c \
		src/ft_atoi.c \
		src/initialize.c \
		src/main.c \
		src/memory_handler.c \
		src/mutex_handler.c \
		src/mutex_utils.c \
		src/print_handler.c \
		src/sync_handler.c \
		src/thread_handler.c \
		src/time_handler.c \
		src/utils.c
OBJS = $(SRCS:.c=.o)

GREEN				=	\033[0;32m
RESET				=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
		@printf "$(GREEN)==> $(GREEN)Philosophers compiled ✅\n\n$(RESET)"

clean:
		rm -f $(OBJS) $(OBJS_BONUS)
		@printf "$(GREEN)==> $(GREEN)Philosophers Cleaned ✅\n\n$(RESET)"

fclean: clean
		rm -rf $(NAME)
		@printf "$(GREEN)==> $(GREEN)Philosophers full cleaned ✅\n\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re