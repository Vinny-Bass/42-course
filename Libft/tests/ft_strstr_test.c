#include <stdio.h>
#include <string.h>
#include "../ft_libft.h"

int main () {
   const char haystack[20] = "vinnyBass";
   const char needle[10] = "Bass";
   char *ret;

   ret = ft_strstr(haystack, needle);

   if (strcmp(ret, "Bass"))
	   return (1);
   
   return(0);
}