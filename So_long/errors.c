/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:37:46 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/23 15:37:47 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_error(t_state *state, char *error)
{
	free_memory(state);
	display_error(error);
}

void	display_error(char *error)
{
	ft_printf("Error\n%s\n", error);
	exit(EXIT_FAILURE);
}
