#include <stdio.h>
#include <string.h>
#include "../ft_libft.h"

int main()
{
	const char str[] = "https://www.vinnybass.com";
	const char ch = '.';
	char *ret;

	ret = ft_strrchr(str, ch);

	if (strcmp(ret, ".com") != 0)
		return 1;

	return (0);
}