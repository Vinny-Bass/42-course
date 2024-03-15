#include "philo.h"

int main(int argc, char **argv)
{
	t_state			state;

	validate_args(argc, argv);
	parse_args(&state, argv);
	init_state(&state);
	init_philos(&state);
	start_dinner(&state);
    return (0);
}
