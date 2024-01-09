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

#include "push_swap.h"

void	swap_stack(t_stack **fe, t_stack *se)
{
	int	tmp;

	tmp = (*fe)->n;
	(*fe)->n = se->n;
	se->n = tmp;
}

void	push_stack(t_stack **from, t_stack **to)
{
    t_stack *tmp1;
    t_stack *tmp2;
    t_stack *tmp3;

	tmp1 = (*from)->next;
	if (!(*to))
	{
		tmp2 = create_node((*from)->n);
		*from = tmp1;
		*to = tmp2;
	}
	else {
		tmp2 = (*from);
		tmp3 = (*to);
		*from = tmp1;
		if (tmp1)
			tmp1->prev = NULL;
		*to = tmp2;
		tmp2->prev = NULL;
		tmp2->next = tmp3; 
		tmp3->prev = tmp2;
	}

	return ;
}

void	rotate_stack(t_stack **stack, int reverse)
{
	t_stack	*last;
	t_stack	*tmp;

	if (reverse)
	{
		tmp = *stack;
		last = get_last_node((*stack));
		last->next = tmp;
		last->prev->next = NULL;
		*stack = last;
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
