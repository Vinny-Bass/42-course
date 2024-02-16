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
	t_stack	*stack;
	t_stack	*stack_b;
	
	stack = NULL;
	stack_b = NULL;
	sort(argc, argv, stack, stack_b);
	free_stacks(stack, stack_b);
	return (0);
}
