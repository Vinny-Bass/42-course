#include "../push_swap.h"

/**
 * Sort an stack with 2 numbers
 */
void	sort_two(t_stack **a, t_stack **b)
{
	if ((*a)->n > (*a)->next->n)
		swap('a', a, b);
}