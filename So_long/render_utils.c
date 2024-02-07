/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:28:13 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/31 17:28:14 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_sprite(t_state *state, t_img sprite, int x, int y)
{
	mlx_put_image_to_window(state->mlx, state->win, \
	sprite.img_ptr, x * sprite.x, y * sprite.y);
}
