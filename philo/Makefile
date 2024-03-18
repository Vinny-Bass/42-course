NAME = philo
CC = cc
CFLAGS = -Werror -Wall -Wextra

SRCS =	bonus/arguments.c \
		bonus/dinner_actions.c \
		bonus/dinner.c \
		bonus/errors.c \
		bonus/ft_atoi.c \
		bonus/initialize.c \
		bonus/main.c \
		bonus/memory_handler.c \
		bonus/semaphore_handler.c \
		bonus/semaphore_utils.c \
		bonus/print_handler.c \
		bonus/sync_handler.c \
		bonus/thread_handler.c \
		bonus/time_handler.c \
		bonus/utils.c
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