/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:02:22 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/17 17:02:23 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(char *label, size_t bytes)
{
	void	*res;

	res = malloc(bytes);
	if (!res)
	{
		printf("Error trying to create %s\n", label);
		exit(EXIT_FAILURE);
	}
	return (res);
}

void	clean(t_state *state)
{
	t_philo		*philo;
	int			i;

	i = -1;
	while (++i < state->n_philos)
	{
		philo = state->philos + i;
		safe_mutex_handler(&philo->philo_mutex, DESTROY);
	}
	safe_mutex_handler(&state->write_mtx, DESTROY);
	safe_mutex_handler(&state->table_mtx, DESTROY);
	free(state->forks);
	free(state->philos);
}
