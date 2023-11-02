#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

int main () {
   int val;
   char str[20];
   
   strcpy(str, "98993489");
   val = ft_atoi(str);
   if (val != 98993489)
	return 1;

   strcpy(str, "vinny");
   val = ft_atoi(str);
   if (val != 0)
	return 1;

   return(0);
}