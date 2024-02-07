/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:05:37 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/23 16:05:38 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define GAME_TITLE		"Hello world"
# define WIN_WIDTH		32
# define WIN_HEIGHT		32

# define NO_COLLECTABLES_ERR " Invalid map, no valid path to the collectables"
# define NO_EXIT_ERR "Invalid map, there is no valid path to the exit"

# define WALL			'1'
# define FLOOR			'0'
# define PLAYER			'P'
# define COLLECTABLE	'C'
# define GOSTH			'G'
# define MAP_EXIT		'E'
# define ENEMY			'G'

# define FRONT			1
# define LEFT			2
# define RIGHT			3
# define BACK			4

# define KEY_UP			65362
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_DOWN		65364

# define FLOOR_IMG			"textures/bg.xpm"
# define WALL_IMG			"textures/wall.xpm"
# define COLLECTABLE_IMG	"textures/key.xpm"
# define OPEN_EXIT_IMG		"textures/open_exit.xpm"
# define CLOSED_EXIT_IMG	"textures/closed_exit.xpm"
# define PLAYER_RIGHT_IMG	"textures/player_r.xpm"
# define PLAYER_LEFT_IMG	"textures/player_l.xpm"
# define PLAYER_FRONT_IMG	"textures/player_f.xpm"
# define PLAYER_BACK_IMG	"textures/player_b.xpm"

# define ENEMY_SPRITES	3
# define ENEMY_IMG_1	"textures/ghost.xpm"
# define ENEMY_IMG_2	"textures/ghost_2.xpm"
# define ENEMY_IMG_3	"textures/ghost_3.xpm"

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_img
{
	int		x;
	int		y;
	int		bpp;
	int		sl;
	int		endian;
	void	*img_ptr;
	void	*orig_ptr;
	char	*img_addr;
	char	*orig_addr;
}	t_img;

typedef struct s_map
{
	char			**full;
	int				rows;
	int				columns;
	int				collectables;
	int				exit;
	int				players;
	t_player		player;
}	t_map;

typedef struct s_state
{
	void			*mlx;
	void			*win;
	int				movements;
	int				player_sprite;
	int				map_alloc;
	int				sprites_alloc;
	t_map			map;
	t_img			wall;
	t_img			floor;
	t_img			collectable;
	t_img			*enemies;
	int				enemy_state;
	double			last_enemy_update;
	t_img			open_exit;
	t_img			closed_exit;
	t_img			player_front;
	t_img			player_left;
	t_img			player_right;
	t_img			player_back;
}	t_state;

t_state	*init_state(void);

void	create_window(t_state *state);
void	display_error(char *error);
void	parse_map(t_state *state, char *map_path);
void	game_error(t_state *state, char *error);
void	free_map(t_state *state);
void	validate_rows(t_state *state);
void	validate_columns(t_state *state);
void	validate_map(t_state *state);
void	validate_map_objects(t_state *state);
void	validate_map_path(t_state *state);
void	free_map_cpy(char **map, int rows);
void	init_sprites(t_state *state);
void	render_map(t_state *state);
void	render_sprite(t_state *state, t_img sprite, int x, int y);
void	init_validation(t_state *state, char **map_cpy);
void	blend_images(t_img *dest, t_img *src, int x, int y);
void	destroy_images(t_state *state);
void	free_memory(t_state *state);
void	print_movements(t_state *state);
void	handle_sprites_helper(t_state *state, int x, int y, t_img tmp_img);
void	render_player(t_state *state, int x, int y, t_img floor_img);
void	validate_line(t_state *s, char **l_tmp, int *l_len, char *m_tmp);
void	append_line_to_map(char **map_tmp, char *line_tmp);
void	update_enemy_animation(t_state *state);
char	**validate_map_cpy(t_state *state);
int		is_safe(t_state *state, int x, int y);
int		input_handler(int key, t_state *state);
t_img	copy_image(t_state *state, t_img src);

#endif
