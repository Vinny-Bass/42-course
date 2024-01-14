#include "push_swap.h"

// void print_stack(const char *label, t_stack *stack) {
//     printf("%s: ", label);
//     for (t_stack *curr = stack; curr != NULL; curr = curr->next) {
//         printf("%d ", curr->n);
//     }
//     printf("\n");
// }

int is_ordered(t_stack *stack, int primary_stack)
{
    while (stack && stack->next)
    {
        if (primary_stack && stack->n > stack->next->n) 
            return(0);
        if (!primary_stack && stack->n < stack->next->n) 
            return(0);
        stack = stack->next;
    }
    return (1);
}

static void exec_operations_b(t_stack **a, t_stack **b)
{
    t_stack *last;

    last = get_last_node(*b);
    while (!is_ordered((*b), 0))
    {
        if ((*b)->n < (*b)->next->n)
        {
            swap('b', a, b);
            continue;
        }
        if (last->n > (*b)->n)
        {
            rotate('b', a, b, 1);
            last = get_last_node(*b);
            continue;
        }
        if ((*b)->n > (*b)->next->n)
        {
            push('a', a, b);
        }
    }
}

static void exec_operations_a(t_stack **a, t_stack **b)
{
    t_stack *last;

    last = get_last_node(*a);
    while (!is_ordered((*a), 1))
    {
        if ((*a)->n > (*a)->next->n)
        {
            swap('a', a, b);
            continue;
        }
        if (last->n < (*a)->n)
        {
            rotate('a', a, b, 1);
            last = get_last_node(*a);
            continue;
        }
        if ((*a)->n < (*a)->next->n)
        {
            push('b', a, b);
            exec_operations_b(a, b);
        }
    }
}

void simple_sort(t_stack **a, t_stack **b)
{
    if (!a || !(*a)->next)
        return ;

    exec_operations_a(a, b);
    exec_operations_b(a, b);
    while (*b != NULL)
    {
        push('a', a, b);
        exec_operations_a(a, b);
    }
    return ;
}