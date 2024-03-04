/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:37:39 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/03 18:37:40 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fill_philos(
	char **argv, pthread_mutex_t **forks, \
	t_philo **philos, int max_eats
)
{
	int	i;
	int	n_philosophers;

	n_philosophers = ft_atoi(argv[1]);
	i = 0;
	while (i < n_philosophers)
	{
		pthread_mutex_init(&(*forks)[i], NULL);
		(*philos)[i].id = i + 1;
		(*philos)[i].eats = 0;
		(*philos)[i].time_to_eat = ft_atoi(argv[3]);
		(*philos)[i].time_to_sleep = ft_atoi(argv[4]);
		(*philos)[i].time_to_die = ft_atoi(argv[2]);
		(*philos)[i].max_eats = max_eats;
		(*philos)[i].left_fork = &(*forks)[i];
		(*philos)[i].right_fork = &(*forks)[(i + 1) % n_philosophers];
		i++;
	}
}

int	init_philos(
	t_philo **philos, pthread_mutex_t **forks, \
	char **argv, int max_eats
)
{
	int	n_philosophers;

	n_philosophers = ft_atoi(argv[1]);
	(*philos) = malloc(sizeof(t_philo) * n_philosophers);
	if (!(*philos))
	{
		ft_printf("\033[0;31mError trying to create philosophers\033[0m");
		return (0);
	}
	(*forks) = malloc(sizeof(pthread_mutex_t) * n_philosophers);
	if (!(*forks))
	{
		ft_printf("\033[0;31mError trying to create forks\033[0m");
		return (0);
	}
	fill_philos(argv, forks, philos, max_eats);
	return (1);
}

int	init_threads(
	pthread_t **threads, pthread_t **death_threads,
	int n_philosophers
)
{
	(*threads) = malloc(sizeof(pthread_t) * n_philosophers);
	if (!(*threads))
	{
		ft_printf("\033[0;31mError trying to create threads\033[0m");
		return (0);
	}
	(*death_threads) = malloc(sizeof(pthread_t) * n_philosophers);
	if (!(*death_threads))
	{
		ft_printf("\033[0;31mError trying to create death threads\033[0m");
		return (0);
	}
	return (1);
}
