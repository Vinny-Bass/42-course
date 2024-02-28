#include "philo.h"

void    initialize(int n, t_philo **philos, t_fork **forks)
{
    int i;

    philos = malloc(sizeof(t_philo) * n);
    if (!philos)
        default_exit_error("\033[0;31mError trying to create philosophers\033[0m");
    forks = malloc(sizeof(t_fork) * n);
    if (!forks)
    {
        ft_printf("\033[0;31mError trying to create the forks\033[0m");
        free(philos);
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (i < n)
    {
        pthread_mutex_init(&(*forks)[i]->mutex, NULL);
        (*forks[i])->taken = false;
        (philos[i])->id = i;
        (philos[i])->eating = false;
        (philos[i])->sleeping = false;
        (philos[i])->thinking = false;
        i++;
    }
    return ;
}
