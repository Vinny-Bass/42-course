#include "philo.h"

static int	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (philo->full)
		return (0);
	elapsed = get_time(MILLISECOND) - philo->last_meal_time;
	time_to_die = philo->state->time_to_die / 1e3;
	if (elapsed > time_to_die)
		return (1);
	return (0);
}

static void *death_monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;		
	while (!philo->dead) 
	{
		if (philo_died(philo) && !philo->eating)
		{
			philo->dead = 1;
			print_status(DIED, philo);
			safe_sem_handler(philo->state->simulation_finished, UNLOCK, "", 0);
			break ;
		}
	}
	return (NULL);
}

static void	dinner_handler(t_philo *philo)
{
	safe_sem_handler(philo->state->simulation_start, LOCK, NULL, 0);
	safe_thread_handler(&philo->state->death_monitor, death_monitor, philo, CREATE);
	safe_thread_handler(&philo->state->death_monitor, NULL, NULL, DETACH);
	philo->last_meal_time = get_time(MILLISECOND);
	prevent_double_actions(philo);
	while (!philo->dead && !philo->full)
	{
		if (philo->state->max_meals != -1 && philo->eats >= philo->state->max_meals)
		{
			philo->full = 1;
			break ;
		}
		eat(philo);
		print_status(SLEEPING, philo);
		ft_usleep(philo->state->time_to_sleep);
		think(philo);
	}
	exit(EXIT_SUCCESS);
}

static void *full_monitor(void *arg)
{
	t_state *state;
	int		i;

	state = (t_state *)arg;
	i = -1;
	while (++i < state->n_philos)
		waitpid(state->philos[i].pid, NULL, 0);
	safe_sem_handler(state->simulation_finished, UNLOCK, "", 0);
	return (NULL);
}

void	start_dinner(t_state *state)
{
	int i;
	pid_t	pid;

	if (state->max_meals == 0)
		return ;
	i = -1;
	while (++i < state->n_philos)
	{
		state->start_sim = get_time(MILLISECOND);
		pid = fork();
		if (pid < 0)
			exit_error("Fork failed");
		if (pid == 0)
		{
			dinner_handler(&state->philos[i]);
			exit(EXIT_SUCCESS);
		} 
		else
			state->philos[i].pid = pid;
	}
	safe_thread_handler(&state->full_monitor, full_monitor, state, CREATE);
	i = -1;
	while (++i < state->n_philos)
		safe_sem_handler(state->simulation_start, UNLOCK, "", 0);
	safe_sem_handler(state->simulation_finished, LOCK, NULL, 0);
	safe_thread_handler(&state->full_monitor, NULL, NULL, DETACH);
}
