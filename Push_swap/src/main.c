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

static void	validate_args(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
		{
			ft_printf("Error\nInvalid arg: %s\n", argv[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

static void	fill_stack(t_stack **stack, char **argv, int *i)
{
	t_stack	*node;

	while (*i > 0)
	{
		node = create_node(ft_atoi(argv[*i]));
		if (!node)
		{
			ft_printf("Error\nError creating node");
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		add_node_on_top(stack, node);
		*i = *i - 1;
	}
}

static void	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->n == checker->n)
			{
				ft_printf("Error\nDuplicate Number: %d", checker->n);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
			checker = checker->next;
		}
		current = current->next;
	}
}

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
