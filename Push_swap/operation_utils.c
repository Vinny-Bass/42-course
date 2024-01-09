#include "push_swap.h"

void swap_stack(t_stack *fe, t_stack *se)
{
    int tmp;
    
    tmp = fe->n;
    fe->n = se->n;
    se->n = tmp;
}

void push_stack(t_stack **s1, t_stack **s2)
{
    t_stack *tmp;

    tmp = (*s1)->next;
    ft_lstadd_front(s2, *s1);
    *s1 = tmp;
}

void rotate_stack(t_stack **stack, int reverse)
{
    t_stack *last;
    t_stack *tmp;

    if (!reverse)
    {
        tmp = *stack;
        last = get_last_node((*stack));
        last->next = tmp;
        last->prev->next = NULL;
        *stack = last;
    }
    else
    {
        tmp = *stack;
        last = get_last_node((*stack));
        last->next = tmp;
        *stack = tmp->next;
        tmp->next = NULL;
    }
    return ;
}