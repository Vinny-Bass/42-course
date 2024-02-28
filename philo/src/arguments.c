#include "philo.h"

bool    validate_args(int argc, char **argv)
{
    if (argc <= 4)
    {
        ft_printf("Invalid args, usage: <n_of_p> <t_to_die> <t_to_eat> <t_to_sleep>");
        exit(EXIT_FAILURE);
    }
}