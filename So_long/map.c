/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:36:05 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/23 15:36:06 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->map.rows)
	{
		free(state->map.full[i]);
		i++;
	}
	free(state->map.full);
}

void	init_map(t_state *state)
{
	state->map.collectables = 0;
	state->map.exit = 0;
	state->map.players = 0;
	state->map.columns = ft_strlen(state->map.full[0]) - 1;
	state->map_alloc = 1;
}

static void	check_for_empty_line(char *map, t_state *state)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		game_error(state, "Invalid map \
		The map have an empty line right at the beginning");
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free (map);
		game_error(state, "Invalid map \
		The map have an empty line at the end");
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			game_error(state, "Invalid map \
			The map have an empty line at the middle");
		}
		i++;
	}
}

void	parse_map(t_state *state, char *map_path)
{
	int		map_fd;
	char	*map_tmp;
	char	*line_tmp;
	int		line_len;

	map_fd = open(map_path, O_RDONLY);
	map_tmp = ft_strdup("");
	line_len = 0;
	state->map.rows = 0;
	while (1)
	{
		line_tmp = get_next_line(map_fd);
		if (!line_tmp)
			break ;
		validate_line(state, &line_tmp, &line_len, map_tmp);
		append_line_to_map(&map_tmp, line_tmp);
		free(line_tmp);
		state->map.rows++;
	}
	close(map_fd);
	check_for_empty_line(map_tmp, state);
	state->map.full = ft_split(map_tmp, '\n');
	init_map(state);
	free(map_tmp);
}

void	validate_map(t_state *state)
{
	validate_rows(state);
	validate_columns(state);
	validate_map_objects(state);
	validate_map_path(state);
}
