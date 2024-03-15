#include "philo.h"

void	set_bool(t_mtx *mtx, int *dest, int value)
{
	safe_mutex_handler(mtx, LOCK);
	*dest = value;
	safe_mutex_handler(mtx, UNLOCK);
}

int	get_bool(t_mtx *mtx, int *value)
{
	int res;

	safe_mutex_handler(mtx, LOCK);
	res = *value;
	safe_mutex_handler(mtx, UNLOCK);
	return (res);
}

void	set_long(t_mtx *mtx, long *dest, long value)
{
	safe_mutex_handler(mtx, LOCK);
	*dest = value;
	safe_mutex_handler(mtx, UNLOCK);
}

long	get_long(t_mtx *mtx, long *value)
{
	long res;

	safe_mutex_handler(mtx, LOCK);
	res = *value;
	safe_mutex_handler(mtx, UNLOCK);
	return (res);
}

int	simulation_finished(t_state *state)
{
	return (get_bool(&state->table_mtx, &state->simulation_finished));
}