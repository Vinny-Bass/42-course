#include "push_swap.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void print_stack(const char *label, t_stack *stack) {
    printf("%s: ", label);
    for (t_stack *curr = stack; curr != NULL; curr = curr->next) {
        printf("%d ", curr->n);
    }
    printf("\n");
}