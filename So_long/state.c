/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:33:46 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/23 15:33:48 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_state	*init_state(void)
{
	t_state	*state;

	state = malloc(sizeof(*state));
	if (!state)
		display_error("Error initing the game state");
	state->mlx = NULL;
	state->win = NULL;
	state->map_alloc = 0;
	state->sprites_alloc = 0;
	state->enemy_state = 0;
	state->last_enemy_update = (double)clock() / CLOCKS_PER_SEC;
	state->movements = 0;
	state->player_sprite = RIGHT;
	return (state);
}
