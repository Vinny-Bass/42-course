/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <vsouza-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:02:07 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/03/20 19:32:01 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sem_err_handler(int status, t_opcode code)
{
	if (status == 0)
		return ;
	if (status == EAGAIN && code == LOCK)
		exit_error("The semaphore is already locked.");
	else if (status == EDEADLK && code == LOCK)
		exit_error("A deadlock was detected.");
	else if (status == EINTR && (code == LOCK || code == INIT))
		exit_error(" The call was interrupted by a signal.");
	else if (status == EINVAL)
		exit_error("sem is not a valid semaphore descriptor.");
	else if (status == EACCES && (code == INIT || code == UNLINK))
		exit_error("Wrong permissions for create or unlink");
	else if (status == EEXIST && code == INIT)
		exit_error("O_CREAT and O_EXCL were specified \
		and the semaphore exists.");
	else if (status == EMFILE && code == INIT)
		exit_error("The process has already reached its limit for \
		semaphores or file descriptors in use.");
	else if (status == ENFILE && code == INIT)
		exit_error("Too many semaphores opened.");
	else if (status == ENOENT && (code == INIT || code == UNLINK))
		exit_error("O_CREAT is not set and the named semaphore \
		does not exist.");
	else if (status == ENOSPC && code == INIT)
		exit_error("Insufficient space available to create the semaphore.");
}

sem_t	*safe_sem_handler(sem_t *sem, t_opcode code, char *label, int value)
{
	if (code == LOCK)
		sem_err_handler(sem_wait(sem), code);
	else if (code == UNLOCK)
		sem_err_handler(sem_post(sem), code);
	else if (code == INIT)
	{
		sem_err_handler(sem_unlink(label), UNLINK);
		return (sem_open(label, O_CREAT, 0600, value));
	}
	else if (code == UNLINK)
		sem_err_handler(sem_unlink(label), code);
	else if (code == DESTROY)
		sem_err_handler(sem_close(sem), code);
	else
		exit_error("Invalid semaphore handler code");
	return (NULL);
}
