/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:56:37 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/24 16:56:39 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.img_addr
			+ (y * img.sl) + (x * img.bpp / 8))));
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.x && y < img.y)
	{
		dst = img.img_addr + (y * img.sl + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

void	blend_images(t_img *dest, t_img *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src->y)
	{
		j = 0;
		while (j < src->x)
		{
			put_pixel_img(*dest, x + i, y + j, get_pixel_img(*src, i, j));
			j++;
		}
		i++;
	}
}

static void	handle_sprites(t_state *state, int x, int y)
{
	t_img	tmp_img;

	tmp_img = copy_image(state, state->floor);
	if (state->map.full[y][x] == FLOOR)
		render_sprite(state, state->floor, x, y);
	if (state->map.full[y][x] == WALL)
		render_sprite(state, state->wall, x, y);
	if (state->map.full[y][x] == COLLECTABLE)
	{
		blend_images(&tmp_img, &state->collectable, 0, 0);
		render_sprite(state, tmp_img, x, y);
	}
	handle_sprites_helper(state, x, y, tmp_img);
	mlx_destroy_image(state->mlx, tmp_img.img_ptr);
}

void	render_map(t_state *state)
{
	int	x;
	int	y;

	y = 0;
	while (y < state->map.rows)
	{
		x = 0;
		while (x < state->map.columns + 1)
		{
			handle_sprites(state, x, y);
			x++;
		}
		y++;
	}
	return ;
}
