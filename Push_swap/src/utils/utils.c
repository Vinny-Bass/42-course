/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:41:48 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/04 19:41:50 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(const char *label, t_stack *stack)
{
	t_stack	*curr;

	curr = stack;
	ft_printf("%s: ", label);
	while (curr != NULL)
	{
		ft_printf("%d ", curr->n);
		curr = curr->next;
	}
	ft_printf("\n");
}

int	is_ordered(t_stack *stack, int primary_stack)
{
	while (stack->next)
	{
		if (primary_stack && stack->n > stack->next->n)
			return (0);
		if (!primary_stack && stack->n < stack->next->n)
			return (0);
		stack = stack->next;
	}
	return (1);
}
/**
 * Free both stacks
 */
void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(&a);
	free_stack(&b);
}
