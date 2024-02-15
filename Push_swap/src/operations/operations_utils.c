/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:37:28 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/05 20:37:29 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack(t_stack **fe, t_stack *se)
{
	int	tmp;

	tmp = (*fe)->n;
	(*fe)->n = se->n;
	se->n = tmp;
}

void	push_stack(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!(*from))
		return ;
	tmp = *to;
	*to = *from;
	*from = (*from)->next;
	(*to)->next = tmp;
	return ;
}

void	rotate_stack(t_stack **stack, int reverse)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!reverse) {
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		last = get_last_node(*stack);
		last->next = tmp;
	}
	else
	{
		tmp = get_last_node((*stack));
		get(*stack, get_stack_size(*stack) - 2)->next = NULL;
		tmp->next = *stack;
		*stack = tmp; 
	}
	return ;
}
