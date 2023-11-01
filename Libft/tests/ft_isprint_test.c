#include <ctype.h>
#include "../ft_libft.h"

int main()
{
    char c;

    c = 'Q';
    if(ft_isprint(c) == 0)
		return 1;

    c = '\n';
    if(ft_isprint(c) != 0)
		return 1;
}