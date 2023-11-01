#include <stdio.h>
#include <string.h>
#include "../ft_libft.h"

int main () {
   char str1[15];
   char str2[15];
   int ret;

   strcpy(str1, "abcdef");
   strcpy(str2, "ABCDEF");

   ret = ft_strncmp(str1, str2, 4);

   if(ret < 0) {
      return 1;
   } else if(ret > 0) {
      return 0;
   } else {
      return 1;
   }
}