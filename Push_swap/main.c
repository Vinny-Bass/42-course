#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    t_stack *stack;
    //t_stack *stack_b;
    t_stack *node;

    if (argc < 2)
        return (0);
    if (!ft_isnumber(argv[1]))
    {
        ft_putstr_fd("Error\n", STDOUT_FILENO);
        return (0);
    }
    i = argc - 1;
    stack = create_node(ft_atoi(argv[i]));
    i--;
    int j = 1;
    while (i > 0)
    {
        // [TODO] verify duplicates
        if (!ft_isnumber(argv[i]))
        {
            ft_putstr_fd("Error\n", STDOUT_FILENO);
            return (0);
        }
        node = create_node(ft_atoi(argv[i]));
        add_node_on_top(&stack, node);
        i--;
        j++;
    }
    //printf("size: %d", j);
    //stack_b = NULL;

    //handle_operations(&stack, &stack_b);
    quick_sort(&stack, j);

    // Print final stacks
    //print_stack("Stack A after", stack);
    //print_stack("Stack b after", stack_b);

    // [TODO] verify for int overflow
    // [TODO] free list after finishes
    return (0);
}