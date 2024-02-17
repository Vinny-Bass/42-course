/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:53:26 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/04 19:53:30 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		stack_size;
	t_stack	*stack;
	t_stack	*stack_b;
	
	stack = NULL;
	stack_b = NULL;
	init(argc, argv, &stack);
	stack_size = get_stack_size(stack);
	if (stack_size == 1 || is_ordered(stack, 1))
	{
		free_stacks(stack, stack_b);
		exit(EXIT_SUCCESS);
	}
	if (stack_size == 2)
		sort_two(&stack, &stack_b);
	else if (stack_size == 3)
		sort_three(&stack, &stack_b);
	else if (stack_size <= 6)
		simple_sort(&stack, &stack_b);
	else
		complex_sort(&stack, &stack_b);
	free_stacks(stack, stack_b);
	return (0);
}
