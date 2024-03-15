#include "philo.h"

void	wait_all_threads(t_state *state)
{
	while (!get_bool(&state->table_mtx, &state->all_threads_ready));
}