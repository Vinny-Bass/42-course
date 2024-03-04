/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:48:27 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/20 20:48:28 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	validate_overlap(char *str)
{
	if (ft_strncmp(str, "2147483647", 10) && ft_atoi(str) == INT_MAX)
	{
		ft_printf("Error\nOverflow arg: %s\n", str);
		return (0);
	}
	if (ft_strncmp(str, "-2147483647", 11) && ft_atoi(str) == INT_MIN)
	{
		ft_printf("Error\nUnderflow arg: %s\n", str);
		return (0);
	}
	return (1);
}

/**
 * Validate the number of arguments and if the arguments are numbers.
 */
static int	validate_args(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
		{
			ft_printf("Error\nInvalid arg: %s\n", argv[i]);
			return (0);
		}
		if (!validate_overlap(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Insert the command line args into a stack
 */
static int	fill_stack(t_stack **stack, char **argv, int *i)
{
	t_stack	*node;

	while (*i > 0)
	{
		node = create_node(ft_atoi(argv[*i]));
		if (!node)
		{
			ft_printf("Error\nError creating node");
			free_stack(stack);
			return (0);
		}
		add_node_on_top(stack, node);
		*i = *i - 1;
	}
	return (1);
}

/**
 * Verify if the stack has an duplicate number
 */
static int	has_duplicates(t_stack *stack)
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
				ft_printf("Error\nDuplicate Number: %d\n", checker->n);
				free_stack(&stack);
				return (0);
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return (1);
}

/**
 * Validate args and fill the stack
 */
void	init(int argc, char **argv, t_stack **a)
{
	int		i;
	t_stack	*new_stack;
	char	**numbers;

	numbers = NULL;
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		argv = numbers;
		argc = count_argc(argv);
	}
	if (!validate_args(argc, argv))
		free_numbers(numbers, 1);
	i = argc - 1;
	new_stack = create_node(ft_atoi(argv[i]));
	if (!new_stack)
		free_numbers(numbers, 1);
	i--;
	if (!fill_stack(&new_stack, argv, &i))
		free_numbers(numbers, 1);
	if (!has_duplicates(new_stack))
		free_numbers(numbers, 1);
	(*a) = new_stack;
	free_numbers(numbers, 0);
}
