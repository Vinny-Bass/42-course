<h1 align="center">
	✏️ Philosophers
</h1>

## 💡 About the project

> _I never thought philosophy would be so deadly._

	The purpose of this project is to solve the dinning philosophers problem using threads, mutexes and semaphores.

---

## ⚠️ Requirements

The function is written in C language and thus needs the **`cc` compiler** and some standard **C libraries** to run.

* One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.
* The philosophers alternatively eat, think, or sleep.
	While they are eating, they are not thinking nor sleeping;
	while thinking, they are not eating nor sleeping;
	and, of course, while sleeping, they are not eating nor thinking
* There are also forks on the table. There are as many forks as philosophers.
Once the string has been received, the server must print it.
* Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
* When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
* Every philosopher needs to eat and should never starve
* Philosophers don’t speak with each other.
* Philosophers don’t know if another philosopher is about to die
* No need to say that philosophers should avoid dying!
* Each philosopher should be a thread.
* There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.
* To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them.

### Bonus

* All the forks are put in the middle of the table.
* They have no states in memory but the number of available forks is represented by
a semaphore.
* Each philosopher should be a process. But the main process should not be a
philosopher.

### Limitations

* Max 25 lines per function
* Max 5 functions per file
* Max 5 vars per function
* Max 4 arguments
* Only the while loop structure is available
* No external libs or functions allowed, except for malloc and free.

---
## 🛠️ Usage

### Instructions

**1. Compiling the program**

To compile, go to the library path and run:

```shell
$ cd philo
$ make
```

**2. Starting the simulation**

```shell
$ ./philo <n_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [max_meals_per_philosopher]
```

For bonus:

**1. Compiling the program**

```shell
$ cd philo
$ make
```

**2. Starting the simulation**

```shell
$ ./philo_bonus <n_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [max_meals_per_philosopher]
```
