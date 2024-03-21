<h1 align="center">
	✏️ Push_swap
</h1>

## 💡 About the project

> _Because Swap_push isn’t as natural._

	The purpose of this project is create am algorithm that will sort one stack using another stack with a set of instructions available, with the minimum number of movements.

---

## ⚠️ Requirements

The function is written in C language and thus needs the **`cc` compiler** and some standard **C libraries** to run.

* You have 2 stacks named a and b..
* At the beginning:
    * The stack a contains a random amount of negative and/or positive numbers
	which cannot be duplicated.
    * The stack b is empty.
* The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
	* sa (swap a): Swap the first 2 elements at the top of stack a.
	* sb (swap b): Swap the first 2 elements at the top of stack b.
	* ss : sa and sb at the same time.
	* pa (push a): Take the first element at the top of b and put it at the top of a.
	* pb (push b): Take the first element at the top of a and put it at the top of b.
	* ra (rotate a): Shift up all elements of stack a by 1.
	* rb (rotate b): Shift up all elements of stack b by 1
	* rr : ra and rb at the same time.
	* rra (reverse rotate a): Shift down all elements of stack a by 1.
	* rrb (reverse rotate b): Shift down all elements of stack b by 1.
	* rrr : rra and rrb at the same time.

### Bonus

* Write a program named checker that takes as an argument the stack a formatted
as a list of integers. The first argument should be at the top of the stack (be careful
about the order). If no argument is given, it stops and displays nothing.
* It will then wait and read instructions on the standard input, each instruction will
be followed by ’\n’. Once all the instructions have been read, the program has to
execute them on the stack received as an argument.
* If after executing those instructions, the stack a is actually sorted and the stack b
is empty, then the program must display "OK" followed by a ’\n’ on the standard
output
* In every other case, it must display "KO" followed by a ’\n’ on the standard output.
* In case of error, you must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments
are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or
is incorrectly formatted.

### Limitations

* Max 25 lines per function
* Max 5 functions per file
* Max 5 vars per function
* Max 4 arguments
* Only the while loop structure is available
* No external libs or functions allowed, except for read, write, malloc, free, exit.

---
## 🛠️ Usage

### Instructions

**1. Compiling the program**

To compile, go to the library path and run:

```shell
$ make
```

**2. Execute**

```shell
$ ./push_swap 5 6 7 2 3 1 99
```

For the bonus:

```shell
$ make bonus
```

**2. Execute**

```shell
$ ./checker 5 6 7 2 3 1 99
```