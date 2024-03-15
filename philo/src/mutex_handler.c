#include "philo.h"

static void	mutex_err_handler(t_mtx *mtx, int status, t_opcode code)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (code == LOCK || code == UNLOCK))
	{
		pthread_mutex_destroy(mtx);
		exit_error("The value specified by the mutex is invalid");
	}
	else if (status == EINVAL && code == INIT)	
		exit_error("The value specified by attr is invalid");
	else if (status == EDEADLK)
		exit_error("A deadlock would occur if the thread blocked waiting for mutex");
	else if (status == EPERM)
		exit_error("The current thread does not hold a lock on mutex");
	else if (status == ENOMEM)
		exit_error("The process cannot allocate enough memory to create another mutex");
	else if (status == EBUSY)
		exit_error("Mutex is locked");
}

void	safe_mutex_handler(t_mtx *mtx, t_opcode code)
{
	if (code == LOCK)
		mutex_err_handler(mtx, pthread_mutex_lock(mtx), code);
	else if (code == UNLOCK)
		mutex_err_handler(mtx, pthread_mutex_unlock(mtx), code);
	else if (code == INIT)
		mutex_err_handler(mtx, pthread_mutex_init(mtx, NULL), code);
	else if (code == DESTROY)
		mutex_err_handler(mtx, pthread_mutex_destroy(mtx), code);
	else
		exit_error("Invalid mutex handler code");
}