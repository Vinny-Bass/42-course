#include "../push_swap.h"

/**
 * Counts the necessary steps to get each values in `stack_a` to the top of the
 * stack. Negative values mean it should be moved with `rra` to save moves.
*/
void	count_steps_a(t_stack *stack_a)
{
	int	len;
	int	str_len;

	str_len = get_stack_size(stack_a);
	len = 0;
	while (stack_a != NULL)
	{
		if (len <= (str_len / 2))
			stack_a->steps_a = len;
		else
			stack_a->steps_a = len - str_len;
		stack_a = stack_a->next;
		len++;
	}
}
/**
 * To count the steps for `stack_b` we need to know what value we want to reach.
 * So we determine the target where the value should be positioned.
*/
static int	get_target(t_stack *stack_a, t_stack *stack_b, int s_b_size)
{
	int		target;
	t_stack	*stack_b_cpy;
	int		lst_value;

	stack_b_cpy = stack_b;
	if (stack_a->n < min(stack_b) || stack_a->n > max(stack_b))
			target = max(stack_b);
	else
	{
		lst_value = get(stack_b, s_b_size - 1)->n;
		while (stack_b_cpy->next != NULL)
		{
			if (stack_a->n < stack_b_cpy->n
				&& stack_a->n > stack_b_cpy->next->n)
				target = stack_b_cpy->next->n;
			else if (stack_a->n
				< lst_value
				&& stack_a->n > stack_b->n)
				target = stack_b->n;
			stack_b_cpy = stack_b_cpy->next;
		}
	}
	return (target);
}

/**
 * Get the position/index of `value` in the `stack`
*/
static int	get_pos(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack->n != value)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

/**
 * Knowing the target we count how many steps we need to move this target to `stack_b`.
 * That value is saved in `steps_b` of the value in `stack_a` that we are
 * looking at.
*/
void	count_steps_b(t_stack *stack_a, t_stack *stack_b)
{
	int	target;
	int	s_b_size;

	s_b_size = get_stack_size(stack_b);
	while (stack_a != NULL)
	{
		target = get_target(stack_a, stack_b, s_b_size);
		if (get_pos(stack_b, target) <= s_b_size / 2)
			stack_a->steps_b = get_pos(stack_b, target);
		else
			stack_a->steps_b = -(s_b_size \
			- get_pos(stack_b, target));
		stack_a = stack_a->next;
	}
}