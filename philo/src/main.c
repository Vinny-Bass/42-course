#include "philo.h"

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
    {
        free(philos);
        free(forks);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ft_atoi(argv[1]); i++) {
        pthread_create(&threads[i], NULL, dinning_handler, &philos[i]);
		pthread_create(&death_threads[i], NULL, death_monitor, &philos[i]);
    }

    for (int i = 0; i < ft_atoi(argv[1]); i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < ft_atoi(argv[1]); i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    free(philos);
    free(forks);
    free(threads);
    free(death_threads);

    return 0;
}