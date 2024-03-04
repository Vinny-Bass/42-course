/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:46:12 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/20 20:46:13 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Get the max number of the stack
 */
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

/**
 * Get the min number of the stack
 */
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

/**
 * Get the position of the node that require less step to be moved to `stack_b`
*/
int	min_steps(t_stack **stack_a)
{
	int		pos;
	int		min_steps;
	int		abs_value;
	int		i;

	i = 0;
	min_steps = INT_MAX;
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

/**
 * Set the total steps need to be taken to move each value in `stack_a`
*/
void	set_total_steps(t_stack *stack_a)
{
	while (stack_a != NULL)
	{
		if ((stack_a->steps_a * stack_a->steps_b) < 0)
			stack_a->total = ft_abs(stack_a->steps_a) \
			+ ft_abs(stack_a->steps_b);
		else
		{
			if (ft_abs(stack_a->steps_a) > ft_abs(stack_a->steps_b))
				stack_a->total = ft_abs(stack_a->steps_a);
			else
				stack_a->total = ft_abs(stack_a->steps_b);
		}
		stack_a = stack_a->next;
	}
}
