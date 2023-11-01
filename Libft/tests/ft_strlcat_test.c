#include <stdio.h>
#include <string.h>
#include "../ft_libft.h"

char run(int size)
{
    char first[] = "This is ";
    char last[] = "a potentially long string";
    int r;
    char buffer[size];

    strcpy(buffer,first);
    r = ft_strlcat(buffer,last,size);
    if( r > size )
        return('t'); //truncated
    else
        return('f'); //full
}

int main()
{
	if (run(16) != 't')
		return 1;
	
	if (run(64) != 'f')
		return 1;
	
	return 0;
}