#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main()
{
	return (0);
	const char haystack[20] = "vinnyBass";
	const char needle[10] = "Bass";
	char *ret;
	char *ret2;

	ret = ft_strnstr(haystack, needle, 9);
	if (strcmp(ret, "Bass") != 0)
		return (1);
	
	ret2 = ft_strnstr(haystack, needle, 4);
	if (ret2 != NULL)
		return (1);

	return (0);
}