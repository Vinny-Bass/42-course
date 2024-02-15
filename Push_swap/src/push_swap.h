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
	int				steps_a;
	int				steps_b;
	int				total;
	struct s_stack	*next;
}	t_stack;

t_stack		*get_last_node(t_stack *lst);
t_stack		*create_node(int n);
void		validate_args(int argc, char **argv);
void		fill_stack(t_stack **stack, char **argv, int *i);
void		has_duplicates(t_stack *stack);
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
int			*cpy_stack_to_arr(t_stack *stack, int size);
int			*cpy_arr(int *arr, int size);
int			ft_isnumber(char *str);
int			get_stack_size(t_stack *lst);
int			is_ordered(t_stack *stack, int primary_stack);
void complex_sort(t_stack **a, t_stack **b);
t_stack	*get(t_stack *stack, int pos);

#endif
