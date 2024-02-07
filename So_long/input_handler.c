/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:20:51 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/02 21:20:52 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_finish(t_state *state, char *phrase)
{
	free_memory(state);
	ft_printf("%s\n", phrase);
	exit(EXIT_SUCCESS);
}

static void	move_player(t_state *state, int x, int y, int p_sprite)
{
	int	last_x;
	int	last_y;

	state->player_sprite = p_sprite;
	last_x = state->map.player.x;
	last_y = state->map.player.y;
	if (state->map.full[y][x] == MAP_EXIT && !state->map.collectables)
		game_finish(state, "You Won");
	if (state->map.full[y][x] == ENEMY)
		game_finish(state, "You Lose");
	else if (state->map.full[y][x] == FLOOR \
	|| state->map.full[y][x] == COLLECTABLE)
	{
		state->map.full[last_y][last_x] = FLOOR;
		if (state->map.full[y][x] == COLLECTABLE)
			state->map.collectables--;
		state->map.player.x = x;
		state->map.player.y = y;
		state->map.full[y][x] = PLAYER;
		state->movements++;
	}
}

int	input_handler(int key, t_state *state)
{
	if (key == KEY_UP)
		move_player(state, state->map.player.x, state->map.player.y - 1, BACK);
	if (key == KEY_LEFT)
		move_player(state, state->map.player.x - 1, state->map.player.y, LEFT);
	if (key == KEY_DOWN)
		move_player(state, state->map.player.x, state->map.player.y + 1, FRONT);
	if (key == KEY_RIGHT)
		move_player(state, state->map.player.x + 1, state->map.player.y, RIGHT);
	return (0);
}
