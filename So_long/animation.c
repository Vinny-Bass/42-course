/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:15:02 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/02 23:15:04 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_enemy_animation(t_state *state)
{
	double	animation_interval;
	double	current_time;

	animation_interval = 0.25;
	current_time = (double)clock() / CLOCKS_PER_SEC;
	if (current_time - state->last_enemy_update >= animation_interval)
	{
		state->enemy_state = (state->enemy_state + 1) % ENEMY_SPRITES;
		state->last_enemy_update = current_time;
	}
}
