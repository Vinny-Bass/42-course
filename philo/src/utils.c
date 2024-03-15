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
