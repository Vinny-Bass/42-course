#include <stdio.h>
#include "../libft.h"

int main()
{
    char c;
    c = 'Q';
	if (ft_isalpha(c) == 0)
		return 1;

    c = 'q';
	if (ft_isalpha(c) == 0)
		return 1;

    c='+';
    if (ft_isalpha(c) == 0)
		return 0;

    return 1;
}