/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:34:23 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/23 15:34:25 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_rows(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->map.rows)
	{
		if (state->map.full[i][0] != WALL)
			game_error(state, "Invalid map,\
			it is not surrounded by walls on left column");
		else if (state->map.full[i][state->map.columns] != WALL)
			game_error(state, "Invalid map,\
			it is not surrounded by walls on rigth column");
		i++;
	}
}

void	validate_columns(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->map.columns)
	{
		if (state->map.full[0][i] != WALL)
			game_error(state, "Invalid map,\
			it is not surrounded by walls on top row");
		else if (state->map.full[state->map.rows - 1][i] != WALL)
			game_error(state, "Invalid map,\
			it is not surrounded by walls on bottom row");
		i++;
	}
}

static void	get_map_objects(t_state *state)
{
	int	x;
	int	y;

	y = 0;
	while (y < state->map.rows)
	{
		x = 0;
		while (x < state->map.columns)
		{
			if (!ft_strchr("CEP01G", state->map.full[y][x]))
				game_error(state, "Invalid map, unexpected object");
			else if (state->map.full[y][x] == PLAYER)
			{
				state->map.players++;
				state->map.player.x = x;
				state->map.player.y = y;
			}
			else if (state->map.full[y][x] == COLLECTABLE)
				state->map.collectables++;
			else if (state->map.full[y][x] == MAP_EXIT)
				state->map.exit++;
			x++;
		}
		y++;
	}
}

void	validate_map_objects(t_state *state)
{
	get_map_objects(state);
	if (state->map.players != 1)
		game_error(state, "Invalid map, invlid number of players");
	if (!state->map.collectables)
		game_error(state, "Invalid map, there is no collectables");
	if (!state->map.exit)
		game_error(state, "Invalid map, there is no exit");
	if (state->map.exit > 1)
		game_error(state, "Invalid map, there is more then one exit");
}

void	free_map_cpy(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
