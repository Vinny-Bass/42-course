#include "philo.h"

void	eat(t_philo *philo)
{
	safe_mutex_handler(philo->first_fork, LOCK);
	print_status(TAKE_FIRST_FORK, philo);
	safe_mutex_handler(philo->second_fork, LOCK);
	print_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECOND));
	philo->eats++;
	print_status(EATING, philo);
	ft_usleep(philo->state->time_to_eat, philo->state);
	if (philo->state->max_meals > 0 && philo->eats == philo->state->max_meals)
		set_bool(&philo->philo_mutex, &philo->full, 1);
	safe_mutex_handler(philo->first_fork, UNLOCK);
	safe_mutex_handler(philo->second_fork, UNLOCK);
}

void	think(t_philo *philo)
{
	print_status(THINKING, philo);
}