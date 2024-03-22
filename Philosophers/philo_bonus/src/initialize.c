/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <vsouza-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:37:39 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/20 20:14:05 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_state(t_state *state)
{
	state->simulation_finished = safe_sem_handler(NULL, \
	INIT, "sim_finished", 0);
	state->simulation_start = safe_sem_handler(NULL, INIT, "sim_start", 0);
	state->forks = safe_sem_handler(NULL, INIT, "forks", state->n_philos);
	state->write_sem = safe_sem_handler(NULL, INIT, "write", 1);
	state->philos = safe_malloc("philos", sizeof(t_philo) * state->n_philos);
}

void	init_philos(t_state *state)
{
	int		i;
	t_philo	*philo;
	sem_t	*philo_sem;

	i = -1;
	philo_sem = safe_sem_handler(NULL, INIT, "philo_sem", 1);
	while (++i < state->n_philos)
	{
		philo = state->philos + i;
		philo->id = i + 1;
		philo->pid = -1;
		philo->eats = 0;
		philo->full = 0;
		philo->dead = 0;
		philo->eating = 0;
		philo->last_meal_time = 0;
		philo->philo_sem = philo_sem;
		philo->state = state;
	}
}
