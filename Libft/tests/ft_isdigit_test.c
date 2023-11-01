#include <stdio.h>
#include "../ft_libft.h"

int main()
{
    char c;
    c='5';
    if (ft_isdigit(c) == 0)
		return 1;

    c='+';
    if (ft_isdigit(c) != 0)
		return 1;

    return 0;
}