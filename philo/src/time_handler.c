#include "philo.h"

long	get_elapsed_time(struct timeval *start)
{
	struct timeval	now;
	long			elapsed_time;

	gettimeofday(&now, NULL);
	elapsed_time = (now.tv_sec - start->tv_sec) * 1000 + (now.tv_usec - start->tv_usec) / 1000;
	return (elapsed_time);
}

long	get_ts_in_ms()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}