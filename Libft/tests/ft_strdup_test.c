#include <stdio.h>
#include <string.h>
#include "../libft.h"
 
int main()
{
    char source[] = "Vinny Bass";
 
    char* target = ft_strdup(source); 
 
    if (strcmp(source, target) != 0)
		  return (1);
    return (0);
}