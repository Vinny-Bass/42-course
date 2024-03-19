#include "philo.h"

static int	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (philo->full)
		return (0);
	elapsed = get_time(MILLISECOND) - philo->last_meal_time;
	time_to_die = philo->time_to_die / 1e3;
	if (elapsed > time_to_die)
		return (1);
	return (0);
}

static void *dinner_monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;		
	while (!philo->dead) 
	{
		if (philo_died(philo) && !philo->eating)
		{
			philo->dead = 1;
			print_status(DIED, philo);
			//safe_sem_handler(philo->write_sem, LOCK, "", 0);
			safe_sem_handler(philo->someone_died_sem, UNLOCK, "", 0);
			break ;
		}
	}
	return (NULL);
}

static void	dinner_handler(t_philo *philo)
{
	safe_sem_handler(philo->table_sem, LOCK, NULL, 0);
	safe_thread_handler(&philo->monitor, dinner_monitor, philo, CREATE);
	safe_thread_handler(&philo->monitor, NULL, NULL, DETACH);
	philo->last_meal_time = get_time(MILLISECOND);
	prevent_double_actions(philo);
	while (!philo->dead && !philo->full)
	{
		//safe_sem_handler(philo->someone_died_sem, LOCK, NULL, 0);
		if (philo->max_meals != -1 && philo->eats >= philo->max_meals)
		{
			philo->full = 1;
			break ;
		}
		eat(philo);
		print_status(SLEEPING, philo);
		ft_usleep(philo->time_to_sleep);
		think(philo);
		//safe_sem_handler(philo->someone_died_sem, UNLOCK, NULL, 0);
	}
	exit(EXIT_SUCCESS);
}

static void *main_monitor(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	int i = -1;
	while (++i < philos[0].n_philos)
		waitpid(philos[i].pid, NULL, 0);
	safe_sem_handler(philos[0].someone_died_sem, UNLOCK, "", 0);
	return (NULL);
}

void	start_dinner(t_philo *philos)
{
	int i;
	int	n_philos;
	pid_t	pid;

	n_philos = philos[0].n_philos;
	sem_t *sim_finished = philos[0].someone_died_sem;
	if (philos[0].max_meals == 0)
		return ;
	i = -1;
	while (++i < n_philos)
	{
		philos[i].start_sim = get_time(MILLISECOND);
		pid = fork();
		if (pid < 0)
			exit_error("Fork failed");
		if (pid == 0)
		{
			dinner_handler(&philos[i]);
			exit(EXIT_SUCCESS);
		} 
		else
			philos[i].pid = pid;
	}
	pthread_t test;
	safe_thread_handler(&test, main_monitor, philos, CREATE);
	i = -1;
	while (++i < n_philos)
		safe_sem_handler(philos[i].table_sem, UNLOCK, "", 0);
	safe_sem_handler(sim_finished, LOCK, NULL, 0);
	safe_thread_handler(&test, NULL, NULL, DETACH);
}
