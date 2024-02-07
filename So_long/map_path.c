/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:49:48 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/23 18:49:49 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**create_map_cpy(t_state *state)
{
	char	**map_cpy;
	int		i;
	int		x;
	int		y;

	map_cpy = validate_map_cpy(state);
	i = 0;
	while (i < state->map.rows)
	{
		map_cpy[i] = malloc((state->map.columns + 1) \
		* sizeof(char));
		i++;
	}
	y = 0;
	while (y < state->map.rows)
	{
		x = 0;
		while (x <= state->map.columns)
		{
			map_cpy[y][x] = '0';
			x++;
		}
		y++;
	}
	return (map_cpy);
}

int	is_safe(t_state *state, int x, int y)
{
	if (x >= 0 && x < state->map.columns)
		if (y >= 0 && y < state->map.rows)
			return (1);
	return (0);
}

static int	check_collectable_path(t_state *s, int x, int y, char **v)
{
	int	direction;

	if (is_safe(s, x, y) && s->map.full[y][x] != WALL && v[y][x] != '1')
	{
		v[y][x] = '1';
		if (s->map.full[y][x] == PLAYER)
			return (1);
		direction = check_collectable_path(s, x - 1, y, v);
		if (direction)
			return (1);
		direction = check_collectable_path(s, x, y - 1, v);
		if (direction)
			return (1);
		direction = check_collectable_path(s, x + 1, y, v);
		if (direction)
			return (1);
		direction = check_collectable_path(s, x, y + 1, v);
		if (direction)
			return (1);
	}
	return (0);
}

static void	validate_collectables(char **map_cpy, t_state *state, int x, int y)
{
	if (!check_collectable_path(state, x, y, map_cpy))
	{
		free_map_cpy(map_cpy, state->map.rows);
		game_error(state, NO_COLLECTABLES_ERR);
	}
}

void	validate_map_path(t_state *state)
{
	char	**map_cpy;
	int		x;
	int		y;

	map_cpy = create_map_cpy(state);
	init_validation(state, map_cpy);
	y = 0;
	while (y < state->map.rows)
	{
		x = 0;
		while (x < state->map.columns)
		{
			if (state->map.full[y][x] == COLLECTABLE)
			{
				free_map_cpy(map_cpy, state->map.rows);
				map_cpy = create_map_cpy(state);
				validate_collectables(map_cpy, state, x, y);
			}
			x++;
		}
		y++;
	}
	free_map_cpy(map_cpy, state->map.rows);
}
