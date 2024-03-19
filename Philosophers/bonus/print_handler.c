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

	elapsed = get_time(MILLISECOND) - philo->start_sim;
	if (philo->full)
		return ;
	safe_sem_handler(philo->write_sem, LOCK, "", 0);
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK))
		print_blue("has taken a fork", philo->id, elapsed);
	else if (status == EATING)	
		print_green("is eating", philo->id, elapsed);
	else if (status == SLEEPING)
		print_blue("is sleeping", philo->id, elapsed);
	else if (status == THINKING)
		print_blue("is thinking", philo->id, elapsed);
	else if (status == DIED)
		print_red("died", philo->id, elapsed);
	if (status != DIED)
		safe_sem_handler(philo->write_sem, UNLOCK, "", 0);
}