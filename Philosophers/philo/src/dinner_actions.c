/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <vsouza-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:57:43 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/17 17:56:39 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	safe_mutex_handler(philo->first_fork, LOCK);
	print_status(TAKE_FIRST_FORK, philo);
	safe_mutex_handler(philo->second_fork, LOCK);
	print_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, \
	get_time(MILLISECOND));
	philo->eats++;
	set_bool(&philo->philo_mutex, &philo->eating, 1);
	print_status(EATING, philo);
	ft_usleep(philo->state->time_to_eat, philo->state);
	set_bool(&philo->philo_mutex, &philo->eating, 0);
	if (philo->state->max_meals > 0 && philo->eats == philo->state->max_meals)
		set_bool(&philo->philo_mutex, &philo->full, 1);
	safe_mutex_handler(philo->first_fork, UNLOCK);
	safe_mutex_handler(philo->second_fork, UNLOCK);
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
	ft_usleep(t_think * 0.42, philo->state);
}

void	prevent_double_actions(t_philo *philo)
{
	if (philo->state->n_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(3e4, philo->state);
	}
	else
	{
		if (philo->id % 2)
			think(philo);
	}
}
