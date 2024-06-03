NAME				=	cub3D
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror

MLXFLAGS			=	-lmlx -lXext -lX11
MATH_LIB			= 	-lm

LIBFT_DIR			=	./libs/libft
LIBFT				=	$(LIBFT_DIR)/libft.a
MLX_DIR				=	./libs/mlx
MLX					=	$(MLX_DIR)/libmlx_Linux.a
INCLUDES			=	-I ./includes

SRCS		=	src/main.c 					\
				src/arguments/handler.c		\

GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[0m

all: $(NAME)

$(NAME): $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) $(MLX_FLAGS) $(MATH_LIB) -o $(NAME) $(LIBFT)
	@echo "$(NAME): $(GREEN)$(NAME) was generated$(RESET)"

${LIBFT}:
	@make --no-print-directory -C $(LIBFT_DIR)

clean:
	@make --no-print-directory clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@make --no-print-directory fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
