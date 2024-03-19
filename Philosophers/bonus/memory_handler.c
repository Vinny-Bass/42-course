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

void	clean(t_philo *philos)
{
	int i = -1;
	while (++i < philos[0].n_philos)
		kill(philos[i].pid, SIGKILL);
	safe_sem_handler(NULL, UNLINK, "forks", 0);
	safe_sem_handler(NULL, UNLINK, "table", 0);
	safe_sem_handler(NULL, UNLINK, "write", 0);
	safe_sem_handler(NULL, UNLINK, "sim_finished", 0);
	safe_sem_handler(philos[0].forks, DESTROY, "forks", 0);
	safe_sem_handler(philos[0].write_sem, DESTROY, "table", 0);
	safe_sem_handler(philos[0].someone_died_sem, DESTROY, "write", 0);
	safe_sem_handler(philos[0].table_sem, DESTROY, "sim_finished", 0);
	free(philos);
}