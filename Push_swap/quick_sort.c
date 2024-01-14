#include "push_swap.h"

int top(t_stack *stack) {
    if (stack) {
        return stack->n;
    }
    return -1;  // Return -1 or some invalid value if the stack is empty
}

// Function to merge two stacks
void mergeStacks(t_stack **a, t_stack **b, int sizeA, int sizeB) {
    while (sizeB > 0) {
        if (sizeA > 0 && top(*a) <= top(*b)) {
            rotate('a', a, b, 0);  // Rotate stack A if the top element is in correct position
            print_stack("Stack A after", *a);
            print_stack("Stack b after", *b);
            sizeA--;
        } else {
            push('a', a, b);  // Push from B to A if B's top is smaller or if A is empty
            print_stack("Stack A after", *a);
            print_stack("Stack b after", *b);
            sizeB--;
        }
    }
    // No need to rotate the stack after merging as push and rotate above should result in a sorted stack
}

void quick_sort(t_stack **a, int size) {
    if (size <= 1) {
        return; // Base case for recursion
    }

    // if (size == 2)
    // {
    //     if ((*a)->n > (*a)->n)
    // }

    int pivot = (*a)->n;
    t_stack *b = NULL;
    int leftSize = 0, rightSize = 0;

    // Partitioning phase
    for (int i = 0; i < size - 1; i++) { // Exclude the pivot from this loop
        if ((*a)->n <= pivot) {
            push('b', a, &b); // Move elements <= pivot to stack b]
            print_stack("Stack A after", *a);
            print_stack("Stack b after", b);
            rightSize++;
        } else {
            rotate('a', a, &b, 0); // Keep elements > pivot in stack a
            print_stack("Stack A after", *a);
            print_stack("Stack b after", b);
            leftSize++;
        }
    }

    //printf("--------------------------------\n");
    // Recursively sort each half
    quick_sort(a, leftSize);
    // printf("--------------------------------\n");
    print_stack("Stack A after", *a);
    print_stack("Stack b after", b);
    quick_sort(&b, rightSize);
    // printf("--------------------------------\n");
    print_stack("Stack A after", *a);
    print_stack("Stack b after", b);

    // Merge stacks back together
    while (b != NULL) {
        push('a', a, &b);
        print_stack("Stack A after", *a);
        print_stack("Stack b after", b);
    }
    // push('a', a, &b); // Move the pivot back to stack a
    // print_stack("Stack A after", *a);
    // print_stack("Stack b after", b);
}

