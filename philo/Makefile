NAME = philosophers
CC = cc
CFLAGS = 

SRCS =	src/arguments.c \
		src/main.c \
		src/initialize.c \
		src/thread_handler.c \
		src/time_handler.c \
		src/print_colors.c
OBJS = $(SRCS:.c=.o)

LIBFT = ./libs/libft
LIBFT_LIB = $(LIBFT)/libft.a
FT_PRINT_F = ./libs/ft_printf
FT_PRINT_F_LIB = $(FT_PRINT_F)/libftprintf.a

GREEN				=	\033[0;32m
RESET				=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT)
		@printf "$(GREEN)==> $(GREEN)Libft compiled ✅\n\n$(RESET)"
		make -C $(FT_PRINT_F)
		@printf "$(GREEN)==> $(GREEN)Print_f compiled ✅\n\n$(RESET)"
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(FT_PRINT_F_LIB)
		@printf "$(GREEN)==> $(GREEN)Philosophers compiled ✅\n\n$(RESET)"

clean:
		make clean -C $(LIBFT)
		@printf "$(GREEN)==> $(GREEN)Libft Cleaned✅\n\n$(RESET)"
		make clean -C $(FT_PRINT_F)
		@printf "$(GREEN)==> $(GREEN)Print_f Cleaned✅\n\n$(RESET)"
		rm -f $(OBJS) $(OBJS_BONUS)
		@printf "$(GREEN)==> $(GREEN)Philosophers Cleaned ✅\n\n$(RESET)"

fclean: clean
		make fclean -C $(LIBFT)
		make fclean -C $(FT_PRINT_F)
		rm -rf $(NAME)
		@printf "$(GREEN)==> $(GREEN)Philosophers full cleaned ✅\n\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re