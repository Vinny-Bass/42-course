#include "philo.h"

static void	*dinner_handler(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->state);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECOND));
	safe_mutex_handler(&philo->state->table_mtx, LOCK);
	philo->state->n_threads_running++;
	safe_mutex_handler(&philo->state->table_mtx, UNLOCK);
	prevent_double_actions(philo);
	while (!simulation_finished(philo->state))
	{
		if (philo->full)
			break ;
		eat(philo);
		print_status(SLEEPING, philo);
		ft_usleep(philo->state->time_to_sleep, philo->state);
		think(philo);
	}
	return (NULL);
}

static void	*single_dinner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->state);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECOND));
	safe_mutex_handler(&philo->state->table_mtx, LOCK);
	philo->state->n_threads_running++;
	safe_mutex_handler(&philo->state->table_mtx, UNLOCK);
	print_status(TAKE_FIRST_FORK, philo);
	while (!simulation_finished(philo->state))
		ft_usleep(200, philo->state);
	return (NULL);
}

static int	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (0);
	elapsed = get_time(MILLISECOND) - get_long(&philo->philo_mutex, &philo->last_meal_time);
	time_to_die = philo->state->time_to_die / 1e3;
	if (elapsed > time_to_die)
		return (1);
	return (0);
}

static void *dinner_monitor(void *data)
{
	t_state	*state;
	int 	i;

	state = (t_state *)data;
	while (!all_threads_running(&state->table_mtx, &state->n_threads_running, state->n_philos))
		;
	while (!simulation_finished(state))
	{
		i = -1;
		while (++i < state->n_philos && !simulation_finished(state))
		{
			if (philo_died(state->philos + i))
			{
				set_bool(&state->table_mtx, &state->simulation_finished, 1);
				print_status(DIED, state->philos + i);
			}
		}
	}
	return (NULL);
}

void	start_dinner(t_state *state)
{
	int i;

	i = -1;
	if (state->max_meals == 0)
		return ;
	else if (state->n_philos == 1)
		safe_thread_handler(&state->philos[0].thread_id, single_dinner, &state->philos[0], CREATE);
	else
		while (++i < state->n_philos)
			safe_thread_handler(&state->philos[i].thread_id, dinner_handler, &state->philos[i], CREATE);
	safe_thread_handler(&state->monitor, dinner_monitor, state, CREATE);
	state->start_sim = get_time(MILLISECOND);
	set_bool(&state->table_mtx, &state->all_threads_ready, 1);
	i = -1;
	while (++i < state->n_philos)
		safe_thread_handler(&state->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&state->table_mtx, &state->simulation_finished, 1);
	safe_thread_handler(&state->monitor, NULL, NULL, JOIN);
}