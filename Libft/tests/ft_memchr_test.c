#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main () {
   const char str[] = "https://www.vinnybass.com";
   const char ch = '.';
   char *ret;

   ret = ft_memchr(str, ch, strlen(str));

    if (strcmp(ret, ".vinnybass.com"))
		return (1);

   return(0);
}