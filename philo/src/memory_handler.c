#include "philo.h"

void	*safe_malloc(char *label, size_t bytes)
{
	void	*res;
	res = malloc(bytes);
	if (!res)
	{
		printf("Error trying to create %s\n", label);
		exit(EXIT_FAILURE);
	}
	return (res);
}