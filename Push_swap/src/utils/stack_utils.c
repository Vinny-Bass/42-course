/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:37:49 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/05 20:37:50 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_last_node(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	add_node_on_top(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

/**
 * Create and initialize a new node part of the stack
 */
t_stack	*create_node(int n)
{
	t_stack	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->steps_a = 0;
	node->steps_b = 0;
	node->total = 0;
	node->next = NULL;
	return (node);
}

/**
 * Return the stack size
 */
int	get_stack_size(t_stack *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

/**
 * Get a node in the stack in an specific position
 */
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
