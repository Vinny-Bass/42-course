#include <stdio.h>
#include <string.h>
#include "../ft_libft.h"

int main () {
   char dest[] = "oldstring";
   const char src[]  = "newstring";

   ft_memmove(dest, src, 9);
   if (strcmp(dest, src) != 0)
	return (1);

   return(0);
}