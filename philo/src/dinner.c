#include "philo.h"

static void	*dinner_handler(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->state);
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

void	start_dinner(t_state *state)
{
	int i;

	i = -1;
	if (state->max_meals == 0)
		return ;
	else if (state->n_philos == 1)
		return ;
	else
		while (++i < state->n_philos)
			safe_thread_handler(&state->philos[i].thread_id, dinner_handler, &state->philos[i], CREATE);
	state->start_sim = get_time(MILLISECOND);
	set_bool(&state->table_mtx, &state->all_threads_ready, 1);
	i = -1;
	while (++i < state->n_philos)
		safe_thread_handler(&state->philos[i].thread_id, NULL, NULL, JOIN);
}