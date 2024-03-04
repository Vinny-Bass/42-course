/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:42:18 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/20 20:42:19 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Sort an stack with 3 numbers
 */
void	sort_three(t_stack **a, t_stack **b)
{
	int	one;
	int	two;
	int	three;

	one = (*a)->n;
	two = (*a)->next->n;
	three = (*a)->next->next->n;
	if (one < two && two > three && one < three)
	{
		rotate('a', a, b, 0);
		swap('a', a, b);
		rotate('a', a, b, 1);
	}
	else if (one > two && two > three && one > three)
	{
		swap('a', a, b);
		rotate('a', a, b, 1);
	}
	else if (one > two && two < three && one < three)
		swap('a', a, b);
	else if (one < two && two > three && one > three)
		rotate('a', a, b, 1);
	else if (one > two && two < three && one > three)
		rotate('a', a, b, 0);
}
