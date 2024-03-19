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

typedef struct	s_state t_state;

typedef struct	s_philo
{
	pid_t				pid;
	int					id;
	int					eats;
	int					full;
	int					dead;
	int					eating;
	long				last_meal_time;
	t_state				*state;
}	t_philo;

struct s_state
{
	pthread_t			death_monitor;
	pthread_t			full_monitor;
	int					n_philos;
	long				start_sim;
	int					max_meals;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	sem_t				*forks;
	sem_t				*simulation_finished;
	sem_t				*simulation_start;
	sem_t				*write_sem;
	t_philo				*philos;
};

// errors
void	exit_error(char *err);

// threads
void	safe_thread_handler(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode code);


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
void	parse_args(t_state *state, char **argv);
void	init_state(t_state *state);
void	init_philos(t_state *state);
void	start_dinner(t_state *state);
void	clean(t_state *state);

#endif
