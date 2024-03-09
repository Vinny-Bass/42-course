#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo {
	int				id;
	int				eats;
	int				max_eats;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	struct timeval	last_meal_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_cond_t	*condition;
} t_philo;

void    validate_args(int argc, char **argv);
int		init_philos(t_philo **philos, pthread_mutex_t **forks, char **argv, int max_eats);
int		init_threads(pthread_t **threads, pthread_t **death_threads, int n_philosophers);
long	get_elapsed_time(struct timeval *start);
long	get_ts_in_ms();
void	*dinning_handler(void *arg);
void	*death_monitor(void *arg);
void	print_red(char *msg, int id, long time);
void	print_blue(char *msg, int id, long time);
void	print_green(char *msg, int id, long time);
int     ft_atoi(const char *str);
void	exit_gracefully(t_philo *philos, pthread_mutex_t *forks);

#endif
