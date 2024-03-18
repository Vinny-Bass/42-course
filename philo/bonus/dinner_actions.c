#include "philo.h"

void	eat(t_philo *philo)
{
	safe_sem_handler(philo->forks, LOCK, "", 0);
	print_status(TAKE_FIRST_FORK, philo);
	safe_sem_handler(philo->forks, LOCK, "", 0);
	print_status(TAKE_SECOND_FORK, philo);
	philo->last_meal_time = get_time(MILLISECOND);
	philo->eats++;
	philo->eating = 1;
	print_status(EATING, philo);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	// if (philo->max_meals > 0 && philo->eats == philo->state->max_meals)
	// 	philo->full = 1;
	safe_sem_handler(philo->forks, UNLOCK, "", 0);
	safe_sem_handler(philo->forks, UNLOCK, "", 0);
}

void	think(t_philo *philo)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	print_status(THINKING, philo);
	if (philo->n_philos %2 == 0)
		return ;
	t_eat = philo->time_to_eat;
	t_sleep = philo->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	ft_usleep(t_think * 0.42);
}

void	prevent_double_actions(t_philo *philo)
{
	if (philo->n_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(3e4);
	}
	else
	{
		if (philo->id % 2)
			think(philo);
	}
}