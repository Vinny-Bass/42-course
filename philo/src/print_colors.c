#include "philo.h"

void	print_red(char **msg, int id, long time)
{
	printf("\033[1;31m");
	printf("%u %d %s\n", time, id, msg);
	printf("\033[0m");
}

void	print_blue(char **msg, int id, long time)
{
	printf("\033[0;34m");
	printf("%u %d %s\n", time, id, msg);
	printf("\033[0m");
}

void	print_green(char **msg, int id, long time)
{
	printf("\033[1;32m");
	printf("%u %d %s\n", time, id, msg);
	printf("\033[0m");
}