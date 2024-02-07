/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:37:03 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/23 15:37:05 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validate_args(int argc, char **argv)
{
	char	*map_arg;
	int		map_arg_len;

	if (argc != 2)
		display_error("Invalid arguments, Usage: ./game <path_to_map>");
	map_arg = argv[1];
	map_arg_len = ft_strlen(map_arg);
	if (!ft_strnstr(map_arg, ".ber", map_arg_len))
		display_error("The map should be in the '.ber' format");
	if (open(map_arg, O_RDONLY) == -1)
		display_error("Map file not founded");
	return ;
}

static int	loop_hook(t_state *state)
{
	update_enemy_animation(state);
	render_map(state);
	print_movements(state);
	return (0);
}

int	main(int argc, char **argv)
{
	t_state	*state;

	validate_args(argc, argv);
	state = init_state();
	parse_map(state, argv[1]);
	validate_map(state);
	create_window(state);
	init_sprites(state);
	mlx_hook(state->win, KeyPress, KeyPressMask, input_handler, state);
	mlx_loop_hook(state->mlx, loop_hook, state);
	mlx_loop(state->mlx);
	free_memory(state);
	return (0);
}
