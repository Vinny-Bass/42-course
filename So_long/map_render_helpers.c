/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:01:51 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/01 00:01:52 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_pixel(t_img src, t_img *dest)
{
	int	x;
	int	y;
	int	pixel;

	y = 0;
	while (y < src.y)
	{
		x = 0;
		while (x < src.x)
		{
			pixel = *(int *)(src.img_addr + (y * src.sl + x * (src.bpp / 8)));
			*(int *) \
			(dest->img_addr + (y * (dest->sl) + x * (dest->bpp / 8))) = pixel;
			x++;
		}
		y++;
	}
	return ;
}

t_img	copy_image(t_state *state, t_img src)
{
	t_img	dest;
	int		bpp;
	int		sl;
	int		endian;

	dest.img_ptr = mlx_new_image(state->mlx, src.x, src.y);
	dest.img_addr = mlx_get_data_addr(dest.img_ptr, &bpp, &sl, &endian);
	if (dest.img_ptr == NULL || dest.img_addr == NULL)
		game_error(state, "Not possible to create a img copy");
	dest.x = src.x;
	dest.y = src.y;
	dest.bpp = bpp;
	dest.sl = sl;
	dest.endian = endian;
	copy_pixel(src, &dest);
	return (dest);
}

void	render_player(t_state *state, int x, int y, t_img floor_img)
{
	t_img	sprite;

	if (state->player_sprite == RIGHT)
		sprite = state->player_right;
	if (state->player_sprite == LEFT)
		sprite = state->player_left;
	if (state->player_sprite == FRONT)
		sprite = state->player_front;
	if (state->player_sprite == BACK)
		sprite = state->player_back;
	blend_images(&floor_img, &sprite, 0, 0);
	render_sprite(state, floor_img, x, y);
}

void	handle_sprites_helper(t_state *state, int x, int y, t_img tmp_img)
{
	t_img	exit_state;

	if (state->map.full[y][x] == ENEMY)
	{
		blend_images(&tmp_img, &state->enemies[state->enemy_state], 0, 0);
		render_sprite(state, tmp_img, x, y);
	}
	if (state->map.full[y][x] == MAP_EXIT)
	{
		if (state->map.collectables)
			exit_state = state->closed_exit;
		else
			exit_state = state->open_exit;
		blend_images(&tmp_img, &exit_state, 0, 0);
		render_sprite(state, tmp_img, x, y);
	}
	if (state->map.full[y][x] == PLAYER)
		render_player(state, x, y, tmp_img);
}
