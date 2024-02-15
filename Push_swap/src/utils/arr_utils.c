/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:44:20 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/04 19:44:22 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*cpy_stack_to_arr(t_stack *stack, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size + 1);
	if (!arr)
	{
		trigger_error(stack, "Error trying to copy \
		the stack to an array");
	}
	while (stack != NULL)
	{
		arr[i++] = stack->n;
		stack = stack->next;
	}
	return (arr);
}

int	*cpy_arr(int *arr, int size)
{
	int	i;
	int	*cpy;

	i = 0;
	cpy = (int *) malloc (sizeof(int) * size);
	if (!arr || !cpy)
		return (NULL);
	while (i < size)
	{
		cpy[i] = arr[i];
		i++;
	}
	return (cpy);
}
