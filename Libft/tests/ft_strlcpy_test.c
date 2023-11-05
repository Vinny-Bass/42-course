#include <stdio.h>
#include <string.h>
#include "../libft.h"

char* test(int size)
{
    char string[] = "Hello there, Venus";
    static char buffer[19];
    int r;

    r = ft_strlcpy(buffer,string,size);

    return buffer;
}

int main()
{
    if (strcmp(test(19), "Hello there, Venus") != 0)
		return 1;
    if (strcmp(test(10), "Hello the") != 0)
		return 1;
    if (strcmp(test(1), "") != 0)
		return 1;
    if (strcmp(test(0), "") != 0)
		return 1;

    return(0);
}