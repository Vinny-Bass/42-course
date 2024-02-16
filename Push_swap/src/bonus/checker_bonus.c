#include "../push_swap.h"

static void	exec_step(t_stack **a, t_stack **b, char *step)
{
	if (ft_strncmp(step, "sa\n", 3) == 0)
		swap('a', a, b);
	else if (ft_strncmp(step, "sb\n", 3) == 0)
		swap('b', a, b);
	else if (ft_strncmp(step, "ss\n", 3) == 0)
		swap('s', a, b);
	else if (ft_strncmp(step, "pa\n", 3) == 0)
		push('a', a, b);
	else if (ft_strncmp(step, "pb\n", 3) == 0)
		push('b', a, b);
	else if (ft_strncmp(step, "ra\n", 3) == 0)
		rotate('a', a, b, 0);
	else if (ft_strncmp(step, "rb\n", 3) == 0)
		rotate('b', a, b, 0);
	else if (ft_strncmp(step, "rr\n", 3) == 0)
		rotate('r', a, b, 0);
	else if (ft_strncmp(step, "rra\n", 3) == 0)
		rotate('a', a, b, 1);
	else if (ft_strncmp(step, "rrb\n", 3) == 0)
		rotate('b', a, b, 1);
	else if (ft_strncmp(step, "rrr\n", 3) == 0)
		rotate('r', a, b, 0);
	else
		(ft_printf("\033[0;31mError\n\033[0m"), exit(-1));
}


int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_b;
	char	*step;

	stack = NULL;
	stack_b = NULL;
	init(argc, argv, &stack);
	if (get_stack_size(stack) == 1)
	{
		ft_printf("\033[0;32mOK\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	while (1)
	{
		step = get_next_line(0);
		if (!step || step[0] == '\n')
			break ;
		exec_step(&stack, &stack_b, step);
		free(step);
	}
	free(step);
	if (is_ordered(stack, 1) && get_stack_size(stack_b) == 0)
		ft_printf("\033[0;32mOK\033[0m\n");
	else
		ft_printf("\033[0;31mKO\033[0m\n");
	free_stacks(stack, stack_b);
	return (0);
}
