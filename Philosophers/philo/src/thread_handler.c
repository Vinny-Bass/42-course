/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:08:10 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/17 17:08:11 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	thread_err_handler(int status, t_opcode code)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		exit_error("No resources to create another thread");
	else if (status == EPERM)
		exit_error("The caller does not have appropiate permission");
	else if (status == EINVAL && code == CREATE)
		exit_error("The value specified by attr is invalid");
	else if (status == EINVAL && (code == JOIN || code == DETACH))
		exit_error("The value specified by thread is not joinable");
	else if (status == ESRCH)
		exit_error("No thread found for that thread ID");
	else if (status == EDEADLK)
		exit_error("A  deadlock was detected for this thread");
}

void	safe_thread_handler(pthread_t *thread, void *(*foo)(void *), \
void *data, t_opcode code)
{
	if (code == CREATE)
		thread_err_handler(pthread_create(thread, NULL, foo, data), code);
	else if (code == JOIN)
		thread_err_handler(pthread_join(*thread, NULL), code);
	else if (code == DETACH)
		thread_err_handler(pthread_detach(*thread), code);
	else
		exit_error("Invalid thread handler code");
}
