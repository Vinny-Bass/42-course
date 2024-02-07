/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:33:11 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/23 15:33:16 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_game(t_state *state)
{
	free_memory(state);
	exit(0);
	return (0);
}

static int	key_handler(int keycode, t_state *state)
{
	if (keycode == XK_Escape)
		close_game(state);
	return (0);
}

static void	clear_ui_area(t_state *state, int width, int height)
{
	int		bpp;
	int		sl;
	int		endian;
	void	*img_ptr;
	char	*img_data;

	img_ptr = mlx_new_image(state->mlx, width, height);
	img_data = mlx_get_data_addr(img_ptr, &bpp, &sl, &endian);
	ft_memset(img_data, 0, width * height * (bpp / 8));
	mlx_put_image_to_window(state->mlx, state->win, \
	img_ptr, 0, (WIN_HEIGHT * state->map.rows));
	mlx_destroy_image(state->mlx, img_ptr);
}

void	print_movements(t_state *state)
{
	int		ui_y;
	char	*movements;
	char	*phrase;

	ui_y = WIN_HEIGHT * state->map.rows;
	clear_ui_area(state, WIN_WIDTH * 32, 50);
	movements = ft_itoa(state->movements);
	phrase = ft_strjoin("MOVEMENTS: ", movements);
	mlx_string_put(state->mlx, state->win, 10, ui_y + 10, 0xFFFFFF, phrase);
	free(movements);
	free(phrase);
}

void	create_window(t_state *state)
{
	int	widht;
	int	height;

	widht = WIN_WIDTH * (state->map.columns + 1);
	height = WIN_HEIGHT * state->map.rows + 50;
	state->mlx = mlx_init();
	if (!state->mlx)
		display_error("Error initiating the mlx lib");
	state->win = mlx_new_window(state->mlx, widht, height, GAME_TITLE);
	if (!state->win)
	{
		mlx_destroy_display(state->mlx);
		game_error(state, "Error initiating the window");
	}
	mlx_key_hook(state->win, &key_handler, state);
	mlx_hook(state->win, 17, 0L, close_game, state);
}
