#include "../libft.h"

int main(void)
{
	if (ft_toupper('a') != 'A')
		return 1;
	if (ft_toupper('B') != 'B')
		return 1;
	if (ft_toupper('8') != '8')
		return 1;
	return 0;
}