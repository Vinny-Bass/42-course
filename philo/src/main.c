#include "philo.h"

static void	create_threads(
	pthread_t *threads, pthread_t *death_threads, \
	t_philo *philos, int n
)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_create(&threads[i], NULL, dinning_handler, &philos[i]);
		pthread_create(&death_threads[i], NULL, death_monitor, &philos[i]);
		i++;
	}
	return ;
}

static void	join_threads(pthread_t *threads, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return ;
}

static void	destroy_mutexes(pthread_mutex_t *forks, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	return ;
}

static void	free_resources(
	pthread_t *threads, pthread_t *death_threads, \
	pthread_mutex_t *forks, t_philo *philos
)
{
	free(philos);
	free(forks);
	free(threads);
	free(death_threads);
}

int main(int argc, char **argv)
{
	pthread_mutex_t	*forks;
    pthread_t       *threads;
    pthread_t       *death_threads;
	t_philo			*philos;
	int				max_eats;

	validate_args(argc);
	max_eats = -1;
	if (argc > 5)
		max_eats = ft_atoi(argv[5]);
    forks = NULL;
    threads = NULL;
    death_threads = NULL;
    philos = NULL;
    if(!init_philos(&philos, &forks, argv, max_eats))
        exit(EXIT_FAILURE);
    if(!init_threads(&threads, &death_threads, ft_atoi(argv[1])))
		exit_gracefully(philos, forks);
	create_threads(threads, death_threads, philos, ft_atoi(argv[1]));
	join_threads(threads, ft_atoi(argv[1]));
	destroy_mutexes(forks, ft_atoi(argv[1]));
	free_resources(threads, death_threads, forks, philos);
    return (0);
}
