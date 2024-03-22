/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <vsouza-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:00:22 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/20 19:41:36 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(char *label, size_t bytes)
{
	void	*res;

	res = malloc(bytes);
	if (!res)
	{
		printf("Error trying to create %s\n", label);
		exit(EXIT_FAILURE);
	}
	return (res);
}

void	clean(t_state *state)
{
	int	i;

	i = -1;
	while (++i < state->n_philos)
		kill(state->philos[i].pid, SIGKILL);
	safe_sem_handler(NULL, UNLINK, "forks", 0);
	safe_sem_handler(NULL, UNLINK, "write", 0);
	safe_sem_handler(NULL, UNLINK, "sim_finished", 0);
	safe_sem_handler(NULL, UNLINK, "sim_start", 0);
	safe_sem_handler(NULL, UNLINK, "philo_sem", 0);
	safe_sem_handler(state->forks, DESTROY, "forks", 0);
	safe_sem_handler(state->simulation_finished, DESTROY, "sim_finished", 0);
	safe_sem_handler(state->simulation_start, DESTROY, "sim_start", 0);
	safe_sem_handler(state->write_sem, DESTROY, "write", 0);
	safe_sem_handler(state->philos[0].philo_sem, DESTROY, "philo_sem", 0);
	free(state->philos);
}
