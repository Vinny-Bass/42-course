/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:06:21 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/17 17:06:22 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
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

typedef pthread_mutex_t	t_mtx;

typedef struct s_state	t_state;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	int				eats;
	int				full;
	int				eating;
	long			last_meal_time;
	t_mtx			*first_fork;
	t_mtx			*second_fork;
	t_mtx			philo_mutex;
	t_state			*state;
}	t_philo;

struct	s_state
{
	int			n_philos;
	int			max_meals;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			simulation_finished;
	int			all_threads_ready;
	int			n_threads_running;
	long		start_sim;
	pthread_t	monitor;
	t_philo		*philos;
	t_mtx		*forks;
	t_mtx		table_mtx;
	t_mtx		write_mtx;
};

// errors
void	exit_error(char *err);

// mutex getters and setters
void	set_bool(t_mtx *mtx, int *dest, int value);
void	set_long(t_mtx *mtx, long *dest, long value);
long	get_long(t_mtx *mtx, long *value);
int		get_bool(t_mtx *mtx, int *value);
int		simulation_finished(t_state *state);

// threads
void	safe_thread_handler(pthread_t *thread, void *(*foo)(void *), \
void *data, t_opcode code);
void	wait_all_threads(t_state *state);
int		all_threads_running(t_mtx *mtx, int *threads, int p_n);

// time
long	get_time(t_time_code code);
void	ft_usleep(long usec, t_state *state);

// utils
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// output
void	print_status(t_philo_status status, t_philo *philo);

// memory
void	*safe_malloc(char *label, size_t bytes);

// mutex
void	safe_mutex_handler(t_mtx *mtx, t_opcode code);

// routines
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	prevent_double_actions(t_philo *philo);

// main
void	validate_args(int argc, char **argv);
void	parse_args(t_state *state, char **argv);
void	init_state(t_state *state);
void	init_philos(t_state *state);
void	start_dinner(t_state *state);
void	clean(t_state *state);

#endif
