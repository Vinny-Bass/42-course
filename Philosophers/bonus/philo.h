#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>
# include <semaphore.h>
# include <signal.h>

typedef enum e_opcode
{
	INIT,
	LOCK,
	UNLOCK,
	UNLINK,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}	t_time_code;

typedef enum e_philo_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_philo_status;

typedef struct	s_philo
{
	pid_t				pid;
	pthread_t			monitor;
	int					id;
	int					eats;
	int					full;
	int					dead;
	int					eating;
	int					n_philos;
	long				start_sim;
	int					max_meals;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	long				last_meal_time;
	sem_t				*forks;
	sem_t				*write_sem;
	sem_t				*someone_died_sem;
	sem_t				*table_sem;
	sem_t				*death_sem;
}	t_philo;

// errors
void	exit_error(char *err);

// semaphore getters and setters
void	set_bool(sem_t *sem, int *dest, int value);
// void	set_long(t_mtx *mtx, long *dest, long value);
// long	get_long(t_mtx *mtx, long *value);
// int		get_bool(sem_t *sem, int *value);
// int		simulation_finished(t_state *state);

// threads
void	safe_thread_handler(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode code);
//void	wait_all_processes(t_state *state);
int		all_processes_running(sem_t *sem, int *processes, int p_n);

// time
long	get_time(t_time_code code);
void	ft_usleep(long usec);

// utils
int     ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// output
void	print_status(t_philo_status status, t_philo *philo);

// memory
void	*safe_malloc(char *label, size_t bytes);

// semaphores
sem_t	*safe_sem_handler(sem_t *sem, t_opcode code, char *label, int value);

// routines
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	prevent_double_actions(t_philo *philo);

// main
void    validate_args(int argc, char **argv);
void	parse_args(t_philo *philos, char **argv);
void	init_philos(t_philo *philos, int n_philos);
void	start_dinner(t_philo *philos);
void	clean(t_philo *philos);

#endif
