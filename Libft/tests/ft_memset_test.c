#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main () {
   char str[50];

   strcpy(str,"This is string.h library function");

   ft_memset(str,'$',7);
   if (strcmp(str, "$$$$$$$ string.h library function") != 0)
	return 1;
   
   return(0);
}