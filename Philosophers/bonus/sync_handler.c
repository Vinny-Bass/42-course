#include "philo.h"

// void	wait_all_processes(t_state *state)
// {
// 	while (!get_bool(&state->table_sem, &state->all_process_ready));
// }

int	all_processes_running(sem_t *sem, int *processes, int p_n)
{
	int	res;

	res = 0;
	safe_sem_handler(sem, LOCK, "", 0);
	if (*processes == p_n)
		res = 1;
	safe_sem_handler(sem, UNLOCK, "", 0);
	return (res);
}