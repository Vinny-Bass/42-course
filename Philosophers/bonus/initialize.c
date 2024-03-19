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

void	init_philos(t_philo *philos, int n_philos)
{
	int	i;

	i = -1;
	sem_t *forks = safe_sem_handler(NULL, INIT, "forks", n_philos);
	sem_t *write = safe_sem_handler(NULL, INIT, "write", 1);
	sem_t *sim_finished = safe_sem_handler(NULL, INIT, "sim_finished", 0);
	while (++i < n_philos)
	{
		philos[i].pid = -1;
		philos[i].id = i + 1;
		philos[i].eats = 0;
		philos[i].full = 0;
		philos[i].dead = 0;
		philos[i].start_sim = 0;
		philos[i].eating = 0;
		philos[i].forks = forks;
		philos[i].write_sem = write;
		philos[i].someone_died_sem = sim_finished;
		philos[i].table_sem = safe_sem_handler(NULL, INIT, "table", 0);
	}
}