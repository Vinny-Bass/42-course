NAME = game
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -lXext -lX11

SRCS = errors.c main.c \
		map_utils.c map.c map_path.c map_render.c map_path_helpers.c \
		render_utils.c state.c sprites.c window.c input_handler.c \
		map_render_helpers.c memory.c map_helpers.c animation.c
OBJS = $(SRCS:.c=.o)

FT_PRINT_F_DIR = ./ft_printf
FT_PRINT_F = $(FT_PRINT_F_DIR)/libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
GET_NEXT_LINE_DIR = ./get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/libgetnextline.a

MLX_DIR=./mlx
MLX=$(MLX_DIR)/libmlx_Linux.a

LIB_FLAGS = -L$(MLX_DIR) -L$(FT_PRINT_F_DIR) -lftprintf -L$(LIBFT_DIR) -lft -L$(GET_NEXT_LINE_DIR) -lgetnextline -lmlx_Linux -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(FT_PRINT_F_DIR)
	make -C $(LIBFT_DIR)
	make -C $(GET_NEXT_LINE_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(FT_PRINT_F_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(GET_NEXT_LINE_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(FT_PRINT_F_DIR)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GET_NEXT_LINE_DIR)

re: fclean all

.PHONY: all clean fclean re
