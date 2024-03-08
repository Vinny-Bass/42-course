#include "philo.h"

void	exit_gracefully(t_philo *philos, pthread_mutex_t *forks)
{
	free(philos);
	free(forks);
	exit(EXIT_FAILURE);
}
