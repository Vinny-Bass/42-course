/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:20:18 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/06 20:20:19 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Iterate and free the stack nodes then the stack itself
 */
void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	free_numbers(char **numbers, int success)
{
	int	i;

	if (!numbers && !success)
		return ;
	if (!numbers && success)
		exit(success);
	i = 1;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
	if (success)
		exit(success);
}
