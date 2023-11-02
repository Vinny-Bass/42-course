#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main () {
   const char src[50] = "Vinny Bass";
   char dest[50];
   strcpy(dest,"Heloooo!!");
   ft_memcpy(dest, src, strlen(src)+1);
   if (strcmp(dest, "Vinny Bass") != 0)
	return 1;
   
   return(0);
}