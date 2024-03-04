/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:41:40 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/20 20:41:41 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Execute steps in the stacks as `steps_a` and `steps_b` 
 * values of the specified element in `stack_a`.
 */
static void	execute_steps(t_stack **stack_a, t_stack **stack_b, int pos)
{
	int	i;

	i = 0;
	while (ft_abs(get(*stack_a, pos)->steps_a) > i)
	{
		if (get(*stack_a, pos)->steps_a > 0)
			rotate('a', stack_a, stack_b, 0);
		else
			rotate('a', stack_a, stack_b, 1);
		pos = min_steps(stack_a);
		i++;
	}
	i = 0;
	while (ft_abs(get(*stack_a, pos)->steps_b) > i)
	{
		if (get(*stack_a, pos)->steps_b > 0)
			rotate('b', stack_a, stack_b, 0);
		else
			rotate('b', stack_a, stack_b, 1);
		i++;
	}
}

/**
 * Improve the steps verifying if steps for stack_a and 
 * stack_b have the same symbol witch means we can use 
 * `rr` or `rrr` to move both stacks at the same time 
 * to save moves.
 */
static void	optimize(t_stack **stack_a, t_stack **stack_b, int pos)
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
		set_total_steps(*stack_a);
		pos = min_steps(stack_a);
	}
	execute_steps(stack_a, stack_b, pos);
}

/**
 * To prepare for the final sorting phase, we ensure the largest 
 * value in `stack_b` is at the top, then use `sort_three` 
 * function to order the top three items in `stack_a`.
 */
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

/**
 * The `merge_stacks` function integrates elements from `stack_b`
 * into `stack_a`, ensuring correct ordering. It first aligns the 
 * top elements of `stack_a` by rotating if necessary, then sequentially 
 * moves all elements from `stack_b` to `stack_a`.
 */
static void	merge_stacks(t_stack **stack_a, t_stack **stack_b)
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

/**
 * Initially, this function moves the first two numbers to `stack_b` 
 * for comparison. It then calculates the minimum moves required for 
 * each element in `stack_a` to be optimally positioned in `stack_b`, 
 * considering steps in both stacks. After distributing all but three 
 * elements to stack_b, it organizes the remaining trio in `stack_a` 
 * and employs the `merge_stacks` method for final alignment.
 */
void	complex_sort(t_stack **a, t_stack **b)
{
	int	pos;

	push('b', a, b);
	push('b', a, b);
	while (get_stack_size(*a) > 3)
	{
		count_steps_a(*a);
		count_steps_b(*a, *b);
		set_total_steps(*a);
		pos = min_steps(a);
		optimize(a, b, pos);
		push('b', a, b);
	}
	order_stacks(a, b);
	merge_stacks(a, b);
}
