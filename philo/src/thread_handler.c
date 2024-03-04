#include "philo.h"

void	*dinning_handler(void *arg)
{
	t_philo			*philo;
	struct timeval	start;

	philo = (t_philo *)arg;
	gettimeofday(&start, NULL);
	philo->last_meal_time = start;
	while (philo->max_eats == -1 || philo->eats < philo->max_eats)
	{
		print_blue("is thinking", philo->id, get_ts_in_ms());
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		print_blue("has taken a fork", philo->id, get_ts_in_ms());
		print_green("is eating", philo->id, get_ts_in_ms());
		usleep(philo->time_to_eat * 1000);
		philo->eats++;
		gettimeofday(&philo->last_meal_time, NULL);
		pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
		print_blue("is sleeping", philo->id, get_ts_in_ms());
		usleep(philo->time_to_sleep * 1000);
	}
	return (NULL);
}

void	*death_monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(1000);
		if (get_elapsed_time(&philo->last_meal_time) > philo->time_to_die)
		{
			print_red("is dead", philo->id, get_ts_in_ms());
			exit(EXIT_FAILURE);
		}
	}
	return (NULL);
}