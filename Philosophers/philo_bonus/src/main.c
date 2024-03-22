/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <vsouza-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:59:37 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/20 19:17:48 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_state			state;

	validate_args(argc, argv);
	parse_args(&state, argv);
	if (state.max_meals == 0)
		return (0);
	init_state(&state);
	init_philos(&state);
	start_dinner(&state);
	clean(&state);
	return (0);
}
