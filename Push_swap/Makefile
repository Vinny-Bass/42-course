NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	src/operations/operations_utils.c \
		src/operations/operations.c \
		src/sorting/main.c \
		src/sorting/simple_sort.c \
		src/sorting/sort_three.c \
		src/sorting/sort_two.c \
		src/sorting/complex_sort.c \
		src/utils/main_utils.c \
		src/utils/stack_utils.c \
		src/utils/stack_utils_2.c \
		src/utils/step_counters.c \
		src/utils/memory_utils.c \
		src/utils/utils.c \
		src/main.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = 	src/bonus/operations_utils_bonus.c \
				src/bonus/operations_bonus.c \
				src/sorting/main.c \
				src/sorting/simple_sort.c \
				src/sorting/sort_three.c \
				src/sorting/sort_two.c \
				src/sorting/complex_sort.c \
				src/utils/main_utils.c \
				src/utils/stack_utils.c \
				src/utils/stack_utils_2.c \
				src/utils/step_counters.c \
				src/utils/memory_utils.c \
				src/utils/utils.c \
				src/bonus/checker_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = ./libs/libft
LIBFT_LIB = $(LIBFT)/libft.a
FT_PRINT_F = ./libs/ft_printf
FT_PRINT_F_LIB = $(FT_PRINT_F)/libftprintf.a
GET_NEXT_LINE = ./libs/get_next_line
GET_NEXT_LINE_LIB = $(GET_NEXT_LINE)/libgetnextline.a

GREEN				=	\033[0;32m
RESET				=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT)
		@printf "$(GREEN)==> $(GREEN)Libft compiled ✅\n\n$(RESET)"
		make -C $(FT_PRINT_F)
		@printf "$(GREEN)==> $(GREEN)Print_f compiled ✅\n\n$(RESET)"
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(FT_PRINT_F_LIB)
		@printf "$(GREEN)==> $(GREEN)Push swap compiled ✅\n\n$(RESET)"

bonus: $(OBJS_BONUS)
		make -C $(LIBFT)
		@printf "$(GREEN)==> $(GREEN)Libft compiled ✅\n\n$(RESET)"
		make -C $(FT_PRINT_F)
		@printf "$(GREEN)==> $(GREEN)Print_f compiled ✅\n\n$(RESET)"
		make -C $(GET_NEXT_LINE)
		@printf "$(GREEN)==> $(GREEN)Get Next Line compiled ✅\n\n$(RESET)"
		$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT_LIB) $(FT_PRINT_F_LIB) $(GET_NEXT_LINE_LIB)
		@printf "$(GREEN)==> $(GREEN)Checker compiled ✅\n\n$(RESET)"

clean:
		make clean -C $(LIBFT)
		@printf "$(GREEN)==> $(GREEN)Libft Cleaned✅\n\n$(RESET)"
		make clean -C $(FT_PRINT_F)
		@printf "$(GREEN)==> $(GREEN)Print_f Cleaned✅\n\n$(RESET)"
		rm -f $(OBJS) $(OBJS_BONUS)
		@printf "$(GREEN)==> $(GREEN)Push swap Cleaned ✅\n\n$(RESET)"

fclean: clean
		make fclean -C $(LIBFT)
		make fclean -C $(FT_PRINT_F)
		make fclean -C $(GET_NEXT_LINE)
		rm -rf $(NAME)
		rm -rf $(NAME_BONUS)
		@printf "$(GREEN)==> $(GREEN)Push swap full cleaned ✅\n\n$(RESET)"

re: fclean all

.PHONY: all clean bonus fclean re