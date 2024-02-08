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
	t_stack	*to_move;

	if (!(*from))
		return ;
	to_move = *from;
	*from = to_move->next;
	if (*from)
		(*from)->prev = NULL;
	if (*to)
		(*to)->prev = to_move;
	to_move->next = *to;
	to_move->prev = NULL;
	*to = to_move;
	return ;
}

void	rotate_stack(t_stack **stack, int reverse)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!reverse) {
		tmp = *stack;
		*stack = tmp->next;  // Move the head forward
		last = get_last_node(*stack);
		last->next = tmp;  // Append the old head to the end
		tmp->next = NULL;  // Isolate the old head
	}
	else
	{
		tmp = *stack;
		last = get_last_node((*stack));
		last->next = tmp;
		*stack = tmp->next;
		tmp->next = NULL;
	}
	return ;
}
