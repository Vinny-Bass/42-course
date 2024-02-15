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
	int		i;
	t_stack	*stack;
	t_stack	*stack_b;

	validate_args(argc, argv);
	i = argc - 1;
	stack = create_node(ft_atoi(argv[i]));
	if (!stack)
		return (0);
	i--;
	fill_stack(&stack, argv, &i);
	has_duplicates(stack);
	stack_b = NULL;
	complex_sort(&stack, &stack_b);
	// print_stack("Stack A after", stack);
	// print_stack("Stack b after", stack_b);
	free_stack(&stack);
	free_stack(&stack_b);
	return (0);
}
