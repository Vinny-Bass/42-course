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

t_stack	*get(t_stack *stack, int pos)
{
	int		i;
	t_stack	*node;

	node = stack;
	i = 0;
	while (i < pos)
	{
		i++;
		node = node->next;
	}
	return (node);
}

int	min_steps(t_stack **stack_a)
{
	int		pos;
	int		min_steps;
	int		abs_value;
	int		i;

	i = 0;
	min_steps = 214748367;
	while (i < get_stack_size(*stack_a))
	{
		abs_value = get(*stack_a, i)->total;
		if (abs_value < min_steps)
		{
			min_steps = abs_value;
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->n;
	while (stack != NULL)
	{
		if (stack->n > max)
			max = stack->n;
		stack = stack->next;
	}
	return (max);
}

int	min(t_stack *stack)
{
	int	min;

	min = stack->n;
	while (stack != NULL)
	{
		if (stack->n < min)
			min = stack->n;
		stack = stack->next;
	}
	return (min);
}

int	get_pos(t_stack *stack, int value)
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

static void	move_stack(t_stack **stack_a, t_stack **stack_b, int pos)
{
	int		i;

	i = 0;
	while (abs(get(*stack_a, pos)->steps_a) > i)
	{
		if (get(*stack_a, pos)->steps_a > 0)
			rotate('a', stack_a, stack_b, 0);
		else
			rotate('a', stack_a, stack_b, 1);
		pos = min_steps(stack_a);
		i++;
	}
	i = 0;
	while (abs(get(*stack_a, pos)->steps_b) > i)
	{
		if (get(*stack_a, pos)->steps_b > 0)
			rotate('b', stack_a, stack_b, 0);
		else
			rotate('b', stack_a, stack_b, 1);
		i++;
	}
}

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

void	totalize(t_stack *stack_a)
{
	while (stack_a != NULL)
	{
		if ((stack_a->steps_a * stack_a->steps_b) < 0)
			stack_a->total = abs(stack_a->steps_a) + abs(stack_a->steps_b);
		else
		{
			if (abs(stack_a->steps_a) > abs(stack_a->steps_b))
				stack_a->total = abs(stack_a->steps_a);
			else
				stack_a->total = abs(stack_a->steps_b);
		}
		stack_a = stack_a->next;
	}
}

static void	synergy(t_stack **stack_a, t_stack **stack_b, int pos)
{
	t_stack	*value;

	value = get(*stack_a, pos);
	if (value->steps_a * value->steps_b > 0)
	{
		while (value->steps_a != 0 && value->steps_b != 0)
		{
			if (value->steps_a > 0)
			{
				rotate('r', stack_a, stack_b, 0);
				value->steps_a--;
				value->steps_b--;
			}
			else
			{
				rotate('r', stack_a, stack_b, 1);
				value->steps_a++;
				value->steps_b++;
			}
		}
		totalize(*stack_a);
		pos = min_steps(stack_a);
	}
	move_stack(stack_a, stack_b, pos);
}

static void	order_stacks(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b)->n != max(*stack_b))
	{
		if (max(*stack_b) <= get_stack_size(*stack_b) / 2)
			rotate('b', stack_a, stack_b, 0);
		else
			rotate('b', stack_a, stack_b, 1);
	}
	sort_three(stack_a, stack_b);
}

static void	zipper(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*s_a_cpy;
	int		i;

	i = 3;
	s_a_cpy = get(*stack_a, get_stack_size(*stack_a) - i--);
	while (get_stack_size(s_a_cpy))
	{
		if (max(s_a_cpy) < max(*stack_b))
			push('a', stack_a, stack_b);
		else
		{
			rotate('a', stack_a, stack_b, 1);
			s_a_cpy = get(*stack_a, get_stack_size(*stack_a) - i--);
		}
	}
	while (get_stack_size(*stack_b))
	{
		push('a', stack_a, stack_b);
	}
		
}

void complex_sort(t_stack **a, t_stack **b)
{
    push('b', a, b);
    push('b', a, b);
    while (get_stack_size(*a) > 3)
    {
        count_steps_a(*a);
        count_steps_b(*a, *b);
		totalize(*a);
		int pos = min_steps(a);
		synergy(a, b, pos);
		push('b', a, b);
    }
	order_stacks(a, b);
	zipper(a, b);
}