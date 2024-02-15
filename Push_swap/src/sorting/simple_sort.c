/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:47:50 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/04 19:47:51 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Based on s[0],s[1] and s[size] take the best decision to move until the stack is ordered
 */
static void	exec_operations_b(t_stack **a, t_stack **b)
{
	t_stack	*last;

	last = get_last_node(*b);
	while (*b != NULL && !is_ordered((*b), 0))
	{
		if ((*b)->n < (*b)->next->n)
		{
			swap('b', a, b);
			continue ;
		}
		if (last->n > (*b)->n)
		{
			rotate('b', a, b, 1);
			last = get_last_node(*b);
			continue ;
		}
		if ((*b)->n > (*b)->next->n)
			push('a', a, b);
	}
}

/**
 * Based on s[0],s[1] and s[size] take the best decision to move until the stack is ordered
 */
static void	exec_operations_a(t_stack **a, t_stack **b)
{
	t_stack	*last;

	last = get_last_node(*a);
	while (!is_ordered((*a), 1))
	{
		if ((*a)->n > (*a)->next->n)
		{
			swap('a', a, b);
			last = get_last_node(*a);
			continue ;
		}
		if (last->n < (*a)->n)
		{
			rotate('a', a, b, 1);
			last = get_last_node(*a);
			continue ;
		}
		if ((*a)->n < (*a)->next->n)
			push('b', a, b);
	}
}

/**
 * Simple sort comparing all the possible values to be moved so s[0], s[1]
 * and s[size]
 */
void	simple_sort(t_stack **a, t_stack **b)
{
	if (!a || !(*a)->next)
		return ;
	exec_operations_a(a, b);
	exec_operations_b(a, b);
	while (*b != NULL)
	{
		push('a', a, b);
		exec_operations_a(a, b);
	}
	return ;
}
