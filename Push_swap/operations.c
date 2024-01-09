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

#include "push_swap.h"

void	swap(char command, t_stack **a, t_stack **b)
{
	if (command == 's')
	{
		if (a && (*a)->next)
			swap_stack(a, (*a)->next);
		if (b && (*b)->next)
			swap_stack(b, (*b)->next);
		ft_putstr_fd("ss\n", STDOUT_FILENO);
	}
	if (command == 'a' && (a && (*a)->next))
	{
		swap_stack(a, (*a)->next);
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	}
	if (command == 'b' && (b && (*b)->next))
	{
		swap_stack(b, (*b)->next);
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	}
	return ;
}

void	push(char command, t_stack **a, t_stack **b)
{
	if (!a && !b)
		return ;
	ft_putchar_fd('p', STDOUT_FILENO);
	if (command == 'a')
		push_stack(b, a);
	if (command == 'b')
		push_stack(a, b);
	ft_putchar_fd(command, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return ;
}

void	rotate(char command, t_stack **a, t_stack **b, int inverse)
{
	if (inverse)
		ft_putchar_fd('r', STDOUT_FILENO);
	if (command == 'r')
	{
		if (a && (*a)->next)
			rotate_stack(a, inverse);
		if (b && (*b)->next)
			rotate_stack(b, inverse);
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	}
	if (command == 'a' && (a && (*a)->next))
	{
		rotate_stack(a, inverse);
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	}
	if (command == 'b' && (b && (*b)->next))
	{
		rotate_stack(b, inverse);
		ft_putstr_fd("rb\n", STDOUT_FILENO);
	}
	return ;
}
