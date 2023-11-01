#include "../ft_libft.h"

int main(void)
{
	if (ft_tolower('A') != 'a')
		return 1;
	if (ft_tolower('b') != 'b')
		return 1;
	if (ft_tolower('8') != '8')
		return 1;
	return 0;
}