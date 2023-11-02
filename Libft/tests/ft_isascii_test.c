#include <stdio.h>
#include "../libft.h"

int main(void)
{
	int result;
	
	result = ft_isascii(0x7c);
	if (result == 0)
		return 1;

	result = ft_isascii(0x7d);
	if (result == 0)
		return 1;

	result = ft_isascii(0x80);
	if (result != 0)
		return 1;
		
	return 0;
}