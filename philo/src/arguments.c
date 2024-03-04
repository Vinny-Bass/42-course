#include "philo.h"

void    validate_args(int argc)
{
	if (argc <= 4)
	{
		ft_printf("Invalid args, usage: <n_of_p> <t_to_die> <t_to_eat> <t_to_sleep> [n_p_should_eat]");
		exit(EXIT_FAILURE);
	}
}