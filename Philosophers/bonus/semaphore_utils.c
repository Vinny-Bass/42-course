#include "philo.h"

void	set_bool(sem_t *sem, int *dest, int value)
{
	safe_sem_handler(sem, LOCK, "", 0);
	*dest = value;
	safe_sem_handler(sem, UNLOCK, "", 0);
}

int	get_bool(sem_t *sem, int *value)
{
	int res;

	safe_sem_handler(sem, LOCK, "", 0);
	res = *value;
	safe_sem_handler(sem, UNLOCK, "", 0);
	return (res);
}

// void	set_long(t_mtx *mtx, long *dest, long value)
// {
// 	safe_mutex_handler(mtx, LOCK);
// 	*dest = value;
// 	safe_mutex_handler(mtx, UNLOCK);
// }

// long	get_long(t_mtx *mtx, long *value)
// {
// 	long res;

// 	safe_mutex_handler(mtx, LOCK);
// 	res = *value;
// 	safe_mutex_handler(mtx, UNLOCK);
// 	return (res);
// }

// int	simulation_finished(t_state *state)
// {
// 	return (get_bool(&state->table_sem, &state->simulation_finished));
// }