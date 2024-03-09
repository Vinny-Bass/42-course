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

int	is_digit_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
	{
		printf("Max eat number should be bigger then 0\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[i]) < 1 || ft_atoi(argv[i]) > 200)
	{
		printf("The number of philosophers should be 0 < n <= 200\n");
		exit(EXIT_FAILURE);
	}
	while (++i < 5)
	{
		if (ft_atoi(argv[i]) < 60)
		{
			printf("time_to_die, time_to_eat and time_to_sleep should be >= 60");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

void    validate_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Invalid args, usage: <n_of_p> <t_to_die> <t_to_eat> <t_to_sleep> [n_p_should_eat]");
		exit(EXIT_FAILURE);
	}
	is_digit(argc, argv);
	is_digit_valid(argc, argv);
	return ;
}