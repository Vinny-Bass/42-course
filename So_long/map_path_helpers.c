/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:35:47 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/31 17:35:49 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_exit_path(t_state *s, int x, int y, char **v)
{
	int	direction;

	if (is_safe(s, x, y) && s->map.full[y][x] != WALL && v[y][x] != '1')
	{
		v[y][x] = '1';
		if (s->map.full[y][x] == MAP_EXIT)
			return (1);
		direction = check_exit_path(s, x - 1, y, v);
		if (direction)
			return (1);
		direction = check_exit_path(s, x, y - 1, v);
		if (direction)
			return (1);
		direction = check_exit_path(s, x + 1, y, v);
		if (direction)
			return (1);
		direction = check_exit_path(s, x, y + 1, v);
		if (direction)
			return (1);
	}
	return (0);
}

void	init_validation(t_state *state, char **map_cpy)
{
	int		is_valid;

	is_valid = check_exit_path(state, state->map.player.x, \
	state->map.player.y, \
	map_cpy);
	if (!is_valid)
	{
		free_map_cpy(map_cpy, state->map.rows);
		game_error(state, NO_EXIT_ERR);
	}
}

char	**validate_map_cpy(t_state *state)
{
	char	**map_cpy;

	map_cpy = malloc(state->map.rows * sizeof(char *));
	if (!map_cpy)
		game_error(state, "Not possible to create a map copy");
	return (map_cpy);
}
