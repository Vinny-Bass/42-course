#include "../push_swap.h"

void	sort(int argc, char **argv, t_stack *a, t_stack *b)
{
	int		stack_size;

	init(argc, argv, &a);
	stack_size = get_stack_size(a);
	if (stack_size == 1 || is_ordered(a, 1))
	{
		free_stacks(a, b);
		exit(EXIT_SUCCESS);
	}
	if (stack_size == 2)
		sort_two(&a, &b);
	else if (stack_size == 3)
		sort_three(&a, &b);
	else if (stack_size <= 6)
		simple_sort(&a, &b);
	else
		complex_sort(&a, &b);
	free_stacks(a, b);
}