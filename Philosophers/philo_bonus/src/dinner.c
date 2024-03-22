/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <vsouza-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:57:17 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/20 20:08:31 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (philo->full)
		return (0);
	safe_sem_handler(philo->philo_sem, LOCK, NULL, 0);
	elapsed = get_time(MILLISECOND) - philo->last_meal_time;
	safe_sem_handler(philo->philo_sem, UNLOCK, NULL, 0);
	time_to_die = philo->state->time_to_die / 1e3;
	if (elapsed > time_to_die)
		return (1);
	return (0);
}

static void	*death_monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo_died(philo) && !philo->eating)
		{
			print_status(DIED, philo);
			safe_sem_handler(philo->state->simulation_finished, UNLOCK, "", 0);
			break ;
		}
	}
	return (NULL);
}

static void	dinner_handler(t_philo *philo)
{
	safe_sem_handler(philo->state->simulation_start, LOCK, NULL, 0);
	safe_thread_handler(&philo->state->death_monitor, \
	death_monitor, philo, CREATE);
	safe_thread_handler(&philo->state->death_monitor, NULL, NULL, DETACH);
	safe_sem_handler(philo->philo_sem, LOCK, NULL, 0);
	philo->last_meal_time = get_time(MILLISECOND);
	safe_sem_handler(philo->philo_sem, UNLOCK, NULL, 0);
	prevent_double_actions(philo);
	while (1)
	{
		if (philo->state->max_meals != -1 \
		&& philo->eats >= philo->state->max_meals)
		{
			philo->full = 1;
			break ;
		}
		eat(philo);
		print_status(SLEEPING, philo);
		ft_usleep(philo->state->time_to_sleep);
		think(philo);
	}
}

static void	*full_monitor(void *arg)
{
	t_state	*state;
	int		i;

	state = (t_state *)arg;
	i = -1;
	while (++i < state->n_philos)
		waitpid(state->philos[i].pid, NULL, 0);
	safe_sem_handler(state->simulation_finished, UNLOCK, "", 0);
	return (NULL);
}

void	start_dinner(t_state *state)
{
	pid_t	pid;
	int		i;

	i = -1;
	while (++i < state->n_philos)
	{
		state->start_sim = get_time(MILLISECOND);
		pid = fork();
		if (pid < 0)
			exit_error("Fork failed");
		if (pid == 0)
		{
			dinner_handler(&state->philos[i]);
			exit(EXIT_SUCCESS);
		}
		else
			state->philos[i].pid = pid;
	}
	i = -1;
	safe_thread_handler(&state->full_monitor, full_monitor, state, CREATE);
	safe_thread_handler(&state->full_monitor, NULL, NULL, DETACH);
	while (++i < state->n_philos)
		safe_sem_handler(state->simulation_start, UNLOCK, "", 0);
	safe_sem_handler(state->simulation_finished, LOCK, NULL, 0);
}
