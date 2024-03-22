/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <vsouza-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:56:09 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/17 16:56:53 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if (argv[i][k] < '0' || argv[i][k] > '9')
			{
				printf("Invalid argument: %c", argv[i][k]);
				exit(EXIT_FAILURE);
			}
			k++;
		}
		i++;
	}
	return (0);
}

static void	validate_overlap(char *str)
{
	if (ft_strncmp(str, "2147483647", 10) && ft_atoi(str) == INT_MAX)
		exit_error("Overflow arg");
	if (ft_strncmp(str, "-2147483647", 11) && ft_atoi(str) == INT_MIN)
		exit_error("Underflow arg");
}

static int	is_digit_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		exit_error("Max eat number should be bigger then 0");
	if (ft_atoi(argv[i]) < 1 || ft_atoi(argv[i]) > 200)
		exit_error("The number of philosophers should be 0 < n <= 200");
	while (++i < 5)
	{
		validate_overlap(argv[i]);
		if (ft_atoi(argv[i]) < 60)
			exit_error("time_to_die, time_to_eat and \
			time_to_sleep should be >= 60");
	}
	return (0);
}

void	validate_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Invalid args, usage: <n_of_p> <t_to_die> \
		<t_to_eat> <t_to_sleep> [n_p_should_eat]");
		exit(EXIT_FAILURE);
	}
	is_digit(argc, argv);
	is_digit_valid(argc, argv);
	return ;
}

void	parse_args(t_state *state, char **argv)
{
	state->n_philos = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]) * 1e3;
	state->time_to_eat = ft_atoi(argv[3]) * 1e3;
	state->time_to_sleep = ft_atoi(argv[4]) * 1e3;
	if (argv[5])
		state->max_meals = ft_atoi(argv[5]);
	else
		state->max_meals = -1;
}
