#include <stdio.h>
#include <string.h>
#include "../ft_libft.h"

int main () {
   char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "abcdef", 6);
   memcpy(str2, "ABCDEF", 6);

   ret = ft_memcmp(str1, str2, 5);

   if(ret > 0) {
      return 0;
   } else if(ret < 0) {
      return 1;
   } else {
      return 1;
   }
}