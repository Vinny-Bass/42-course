/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:01:46 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/17 17:01:48 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_state			state;

	validate_args(argc, argv);
	parse_args(&state, argv);
	init_state(&state);
	init_philos(&state);
	start_dinner(&state);
	clean(&state);
	return (0);
}
