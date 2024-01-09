/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsouza-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:31:56 by vsouza-v          #+#    #+#             */
/*   Updated: 2024/01/05 20:31:57 by vsouza-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack		*get_last_node(t_stack *lst);
t_stack		*create_node(int n);
void		swap(char command, t_stack **a, t_stack **b);
void		swap_stack(t_stack **fe, t_stack *se);
void		push(char command, t_stack **a, t_stack **b);
void		push_stack(t_stack **s1, t_stack **s2);
void		rotate(char command, t_stack **a, t_stack **b, int inverse);
void		rotate_stack(t_stack **stack, int reverse);
void		add_node_on_top(t_stack **lst, t_stack *new);
int			ft_isnumber(char *str);
void 		handle_operations(t_stack **a, t_stack **b);

#endif
