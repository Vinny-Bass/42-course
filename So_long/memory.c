/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:21:14 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/01 23:21:18 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_memory(t_state *state)
{
	if (state->sprites_alloc)
		destroy_images(state);
	if (state->map_alloc)
		free_map(state);
	if (state->win)
		mlx_destroy_window(state->mlx, state->win);
	if (state->mlx)
		mlx_destroy_display(state->mlx);
	free(state->mlx);
	free(state);
}

static void	destroy_enemy_images(t_state *state)
{
	int	i;

	i = 0;
	while (i < ENEMY_SPRITES)
	{
		if (state->enemies[i].img_ptr)
			mlx_destroy_image(state->mlx, state->enemies[i].img_ptr);
		i++;
	}
	free(state->enemies);
	return ;
}

void	destroy_images(t_state *state)
{
	if (state->floor.img_ptr)
		mlx_destroy_image(state->mlx, state->floor.img_ptr);
	if (state->player_back.img_ptr)
		mlx_destroy_image(state->mlx, state->player_back.img_ptr);
	if (state->player_front.img_ptr)
		mlx_destroy_image(state->mlx, state->player_front.img_ptr);
	if (state->player_left.img_ptr)
		mlx_destroy_image(state->mlx, state->player_left.img_ptr);
	if (state->player_right.img_ptr)
		mlx_destroy_image(state->mlx, state->player_right.img_ptr);
	if (state->closed_exit.img_ptr)
		mlx_destroy_image(state->mlx, state->closed_exit.img_ptr);
	if (state->open_exit.img_ptr)
		mlx_destroy_image(state->mlx, state->open_exit.img_ptr);
	if (state->collectable.img_ptr)
		mlx_destroy_image(state->mlx, state->collectable.img_ptr);
	if (state->wall.img_ptr)
		mlx_destroy_image(state->mlx, state->wall.img_ptr);
	destroy_enemy_images(state);
	return ;
}
