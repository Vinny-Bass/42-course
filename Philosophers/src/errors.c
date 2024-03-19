#include "philo.h"

void	exit_error(char *err)
{
	printf(
		"\033[1;31m"
		"%s\n"
		"\033[0m",
		err);
	exit(EXIT_FAILURE);
}