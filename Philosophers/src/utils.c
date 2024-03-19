#include "philo.h"

void	ft_usleep(long usec, t_state *state)
{
	long	start;
	long	elapsed;
	long	rem;

	start = get_time(MICROSECOND);
	while(get_time(MICROSECOND) - start < usec)
	{
		if (simulation_finished(state))
			break;
		elapsed = get_time(MICROSECOND) - start;
		rem = usec - elapsed;
		if (rem > 1e3)
			usleep(rem / 2);
		else
			while (get_time(MICROSECOND) - start < usec)
				;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
