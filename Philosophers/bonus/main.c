#include "philo.h"

int main(int argc, char **argv)
{
	t_philo			*philos;

	validate_args(argc, argv);
	philos = safe_malloc("philos", sizeof(t_philo) * ft_atoi(argv[1]));
	parse_args(philos, argv);
	init_philos(philos, ft_atoi(argv[1]));
	start_dinner(philos);
	clean(philos);
    return (0);
}
