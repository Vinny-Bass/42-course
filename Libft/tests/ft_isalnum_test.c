#include <stdio.h>
#include "../libft.h"

int main()
{
    char c;
    int result;

    c = '5';
    result = ft_isalnum(c);
    if (result != 1)
		  return 1;

    c = 'Q';
    result = ft_isalnum(c);
    if (result != 1)
		  return 1;

    c = 'l';
    result = ft_isalnum(c);
    if (result != 1)
		  return 1;

    c = '+';
    result = ft_isalnum(c);
    if (result != 0)
		  return 1;
	
	return 0;
}
