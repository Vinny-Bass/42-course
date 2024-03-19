#include "philo.h"

void	wait_all_threads(t_state *state)
{
	while (!get_bool(&state->table_mtx, &state->all_threads_ready));
}

int	all_threads_running(t_mtx *mtx, int *threads, int p_n)
{
	int	res;

	res = 0;
	safe_mutex_handler(mtx, LOCK);
	if (*threads == p_n)
		res = 1;
	safe_mutex_handler(mtx, UNLOCK);
	return (res);
}