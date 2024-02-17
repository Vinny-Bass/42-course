#include "../push_swap.h"

static void	validate_overlap(char *str)
{
	if (ft_strncmp(str, "2147483647", 10) && ft_atoi(str) == INT_MAX)
	{
		ft_printf("Error\nOverflow arg: %s\n", str);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(str, "-2147483647", 11) && ft_atoi(str) == INT_MIN)
	{
		ft_printf("Error\nUnderflow arg: %s\n", str);
		exit(EXIT_FAILURE);
	}
}

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
		validate_overlap(argv[i]);
		i++;
	}
	return ;
}

/**
 * Insert the command line args into a stack
 */
static void fill_stack(t_stack **stack, char **argv, int *i)
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
static void	has_duplicates(t_stack *stack)
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
				ft_printf("Error\nDuplicate Number: %d\n", checker->n);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
			checker = checker->next;
		}
		current = current->next;
	}
}

/**
 * Validate args and fill the stack
 */
void	init(int argc, char **argv, t_stack **a)
{
	int		i;
	t_stack	*new_stack;

	validate_args(argc, argv);
	i = argc - 1;
	new_stack = create_node(ft_atoi(argv[i]));
	if (!new_stack)
		exit(EXIT_FAILURE);
	i--;
	fill_stack(&new_stack, argv, &i);
	has_duplicates(new_stack);
	(*a) = new_stack;
}
