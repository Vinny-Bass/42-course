#include "philo.h"

static void	print_red(char *msg, int id, long time)
{
	printf(
		"\033[1;31m"
		"%ld %d %s\n"
		"\033[0m",
		time, id, msg
	);
}

static void	print_blue(char *msg, int id, long time)
{
	printf(
		"\033[1;34m"
		"%ld %d %s\n"
		"\033[0m",
		time, id, msg
	);
}

static void	print_green(char *msg, int id, long time)
{
	printf(
		"\033[1;32m"
		"%ld %d %s\n"
		"\033[0m",
		time, id, msg
	);
}

void	print_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = get_time(MILLISECOND) - philo->state->start_sim;
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	safe_mutex_handler(&philo->state->write_mtx, LOCK);
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK) && !simulation_finished(philo->state))
		print_blue("has taken a fork", philo->id, elapsed);
	else if (status == EATING && !simulation_finished(philo->state))	
		print_green("is eating", philo->id, elapsed);
	else if (status == SLEEPING && !simulation_finished(philo->state))
		print_blue("is sleeping", philo->id, elapsed);
	else if (status == THINKING && !simulation_finished(philo->state))
		print_blue("is thinking", philo->id, elapsed);
	else if (status == DIED)
		print_red("died", philo->id, elapsed);
	safe_mutex_handler(&philo->state->write_mtx, UNLOCK);
}