#include "philo.h"

void	print_red(char *msg, int id, long time)
{
	printf(
		"\033[1;31m"
		"%u %d %s\n"
		"\033[0m",
		(unsigned int)time, id, msg
	);
}

void	print_blue(char *msg, int id, long time)
{
	printf(
		"\033[1;34m"
		"%u %d %s\n"
		"\033[0m",
		(unsigned int)time, id, msg
	);
}

void	print_green(char *msg, int id, long time)
{
	printf(
		"\033[1;32m"
		"%u %d %s\n"
		"\033[0m",
		(unsigned int)time, id, msg
	);
}