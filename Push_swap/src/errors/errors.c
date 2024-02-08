/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:49:41 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/02/04 19:49:42 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	trigger_error(t_stack *stack, char *error)
{
	free_stack(&stack);
	ft_printf("Error\n%s\n", error);
	exit(EXIT_FAILURE);
}
