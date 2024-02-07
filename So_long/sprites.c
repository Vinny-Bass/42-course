/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:55:19 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/24 16:55:21 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	create_sprite(void *mlx, char *path, t_state *state)
{
	t_img	sprite;

	sprite.img_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (!sprite.img_ptr)
		game_error(state, "Could not create the sprite");
	sprite.img_addr = mlx_get_data_addr(sprite.img_ptr, \
	&sprite.bpp, &sprite.sl, &sprite.endian);
	return (sprite);
}

static void	init_enemy(t_state *state)
{
	char	**sprites;
	int		i;

	sprites = (char **)malloc(ENEMY_SPRITES * sizeof(char *));
	sprites[0] = ft_strdup(ENEMY_IMG_1);
	sprites[1] = ft_strdup(ENEMY_IMG_2);
	sprites[2] = ft_strdup(ENEMY_IMG_2);
	state->enemies = (t_img *)malloc(ENEMY_SPRITES * sizeof(t_img));
	i = 0;
	while (i < ENEMY_SPRITES)
	{
		state->enemies[i] = create_sprite(state->mlx, sprites[i], state);
		free(sprites[i]);
		i++;
	}
	free(sprites);
}

void	init_sprites(t_state *state)
{
	void	*mlx;

	mlx = state->mlx;
	state->floor = create_sprite(mlx, FLOOR_IMG, state);
	state->wall = create_sprite(mlx, WALL_IMG, state);
	init_enemy(state);
	state->collectable = create_sprite(mlx, COLLECTABLE_IMG, state);
	state->closed_exit = create_sprite(mlx, CLOSED_EXIT_IMG, state);
	state->open_exit = create_sprite(mlx, OPEN_EXIT_IMG, state);
	state->player_right = create_sprite(mlx, PLAYER_RIGHT_IMG, state);
	state->player_left = create_sprite(mlx, PLAYER_LEFT_IMG, state);
	state->player_front = create_sprite(mlx, PLAYER_FRONT_IMG, state);
	state->player_back = create_sprite(mlx, PLAYER_BACK_IMG, state);
	state->sprites_alloc = 1;
}
