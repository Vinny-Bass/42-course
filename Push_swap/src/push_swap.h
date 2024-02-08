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

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_lis_info
{
	int	max_value;
	int	min_value;
	int	max_pos;
	int	min_pos;
}	t_lis_info;

t_stack		*get_last_node(t_stack *lst);
t_stack		*create_node(int n);
void		swap(char command, t_stack **a, t_stack **b);
void		swap_stack(t_stack **fe, t_stack *se);
void		push(char command, t_stack **a, t_stack **b);
void		push_stack(t_stack **s1, t_stack **s2);
void		rotate(char command, t_stack **a, t_stack **b, int inverse);
void		rotate_stack(t_stack **stack, int reverse);
void		add_node_on_top(t_stack **lst, t_stack *n);
void		simple_sort(t_stack **a, t_stack **b);
void		trigger_error(t_stack *stack, char *error);
void		print_stack(const char *label, t_stack *stack);
void		free_stack(t_stack **stack);
int			*cpy_lst_to_arr(t_stack *stack, int size);
int			*cpy_arr(int *arr, int size);
int			ft_isnumber(char *str);
int			get_stack_size(t_stack *lst);
int			is_ordered(t_stack *stack, int primary_stack);

#endif
