/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <vsouza-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:00:48 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/20 20:25:55 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_red(char *msg, int id, long time)
{
	printf(
		"\033[1;31m"
		"%ld %d %s\n"
		"\033[0m",
		time, id, msg);
}

static void	print_blue(char *msg, int id, long time)
{
	printf(
		"\033[1;34m"
		"%ld %d %s\n"
		"\033[0m",
		time, id, msg);
}

static void	print_green(char *msg, int id, long time)
{
	printf(
		"\033[1;32m"
		"%ld %d %s\n"
		"\033[0m",
		time, id, msg);
}

void	print_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = get_time(MILLISECOND);
	if (philo->full)
		return ;
	safe_sem_handler(philo->state->write_sem, LOCK, "", 0);
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK))
		print_blue("has taken a fork", philo->id, elapsed);
	else if (status == EATING)
		print_green("is eating", philo->id, elapsed);
	else if (status == SLEEPING)
		print_blue("is sleeping", philo->id, elapsed);
	else if (status == THINKING)
		print_blue("is thinking", philo->id, elapsed);
	else if (status == DIED)
		print_red("died", philo->id, elapsed);
	if (status != DIED)
		safe_sem_handler(philo->state->write_sem, UNLOCK, "", 0);
}
