/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <vsouza-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:37:39 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/17 17:01:16 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_mtx *forks, int i)
{
	int	n;

	n = philo->state->n_philos;
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[(i + 1) % n];
	}
	else
	{
		philo->first_fork = &forks[(i + 1) % n];
		philo->second_fork = &forks[i];
	}
}

void	init_state(t_state *state)
{
	int	i;

	i = -1;
	state->simulation_finished = 0;
	state->all_threads_ready = 0;
	state->n_threads_running = 0;
	state->philos = safe_malloc("philos", sizeof(t_philo) * state->n_philos);
	state->forks = safe_malloc("forks", sizeof(t_mtx) * state->n_philos);
	safe_mutex_handler(&state->write_mtx, INIT);
	safe_mutex_handler(&state->table_mtx, INIT);
	while (++i < state->n_philos)
		safe_mutex_handler(&state->forks[i], INIT);
}

void	init_philos(t_state *state)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < state->n_philos)
	{
		philo = state->philos + i;
		philo->id = i + 1;
		philo->eats = 0;
		philo->full = 0;
		philo->eating = 0;
		philo->state = state;
		safe_mutex_handler(&philo->philo_mutex, INIT);
		assign_forks(philo, state->forks, i);
	}
}
