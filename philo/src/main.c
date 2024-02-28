#include "philo.h"

int main(int argc, char **argv)
{
    t_philo *philos;
    t_fork  *forks;
    
    validate_args(argc, argv);
    philos = NULL;
    forks = NULL;
    initialize(argv[1], &philos, &forks);
}