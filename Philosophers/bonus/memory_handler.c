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
	int i = -1;
	while (++i < state->n_philos)
		kill(state->philos[i].pid, SIGKILL);
	safe_sem_handler(NULL, UNLINK, "forks", 0);
	safe_sem_handler(NULL, UNLINK, "write", 0);
	safe_sem_handler(NULL, UNLINK, "sim_finished", 0);
	safe_sem_handler(NULL, UNLINK, "sim_start", 0);
	safe_sem_handler(state->forks, DESTROY, "forks", 0);
	safe_sem_handler(state->simulation_finished, DESTROY, "sim_finished", 0);
	safe_sem_handler(state->simulation_start, DESTROY, "sim_start", 0);
	safe_sem_handler(state->write_sem, DESTROY, "write", 0);
	free(state->philos);
}