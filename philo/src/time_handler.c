#include "philo.h"

long	get_time(t_time_code code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		exit_error("gettimeofday fail");
	else if (code == SECOND)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (code == MILLISECOND)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (code == MICROSECOND)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	return (0);
}