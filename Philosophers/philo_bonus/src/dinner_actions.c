/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <vsouza-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:56:54 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/20 17:57:05 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	safe_sem_handler(philo->state->forks, LOCK, "", 0);
	print_status(TAKE_FIRST_FORK, philo);
	safe_sem_handler(philo->state->forks, LOCK, "", 0);
	print_status(TAKE_SECOND_FORK, philo);
	philo->last_meal_time = get_time(MILLISECOND);
	philo->eats++;
	philo->eating = 1;
	print_status(EATING, philo);
	ft_usleep(philo->state->time_to_eat);
	philo->eating = 0;
	if (philo->state->max_meals > 0 && philo->eats == philo->state->max_meals)
		philo->full = 1;
	safe_sem_handler(philo->state->forks, UNLOCK, "", 0);
	safe_sem_handler(philo->state->forks, UNLOCK, "", 0);
}

void	think(t_philo *philo)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	print_status(THINKING, philo);
	if (philo->state->n_philos % 2 == 0)
		return ;
	t_eat = philo->state->time_to_eat;
	t_sleep = philo->state->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	ft_usleep(t_think * 0.42);
}

void	prevent_double_actions(t_philo *philo)
{
	if (philo->state->n_philos % 2 == 0)
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
