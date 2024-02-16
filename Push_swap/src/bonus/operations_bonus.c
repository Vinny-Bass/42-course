/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:34:57 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/05 20:34:58 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(char command, t_stack **a, t_stack **b)
{
	if (command == 's')
	{
		if (a && (*a)->next)
			swap_stack(a, (*a)->next);
		if (b && (*b)->next)
			swap_stack(b, (*b)->next);
	}
	if (command == 'a' && (a && (*a)->next))
		swap_stack(a, (*a)->next);
	if (command == 'b' && (b && (*b)->next))
		swap_stack(b, (*b)->next);
	return ;
}

void	push(char command, t_stack **a, t_stack **b)
{
	if (!a && !b)
		return ;
	if (command == 'a')
		push_stack(b, a);
	if (command == 'b')
		push_stack(a, b);
	return ;
}

void	rotate(char command, t_stack **a, t_stack **b, int inverse)
{
	if (command == 'r')
	{
		if (a && (*a)->next)
			rotate_stack(a, inverse);
		if (b && (*b)->next)
			rotate_stack(b, inverse);
	}
	if (command == 'a' && (a && (*a)->next))
		rotate_stack(a, inverse);
	if (command == 'b' && (b && (*b)->next))
		rotate_stack(b, inverse);
	return ;
}
