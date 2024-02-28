#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"

typedef struct s_fork {
	pthread_mutex_t mutex;
	bool			taken;
} t_fork;

typedef struct s_philo {
	int			id;
	bool		eating;
	bool		thinking;
	bool		sleeping;
	pthread_t	thread;
} t_philo;

void    default_exit_error(char *error);
bool    validate_args(int argc, char **argv);
void    initialize(int n, t_philo **philos, t_fork **forks);


#endif