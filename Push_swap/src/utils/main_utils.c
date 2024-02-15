#include "../push_swap.h"

/**
 * Validate the number of arguments and if the arguments are numbers.
 */
void validate_args(int argc, char **argv)
{
	int i;

	if (argc < 2)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
		{
			ft_printf("Error\nInvalid arg: %s\n", argv[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return;
}

/**
 * Insert the command line args into a stack
 */
void fill_stack(t_stack **stack, char **argv, int *i)
{
	t_stack *node;

	while (*i > 0)
	{
		node = create_node(ft_atoi(argv[*i]));
		if (!node)
		{
			ft_printf("Error\nError creating node");
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		add_node_on_top(stack, node);
		*i = *i - 1;
	}
}

/**
 * Verify if the stack has an duplicate number
 */
void	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->n == checker->n)
			{
				ft_printf("Error\nDuplicate Number: %d", checker->n);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
			checker = checker->next;
		}
		current = current->next;
	}
}