#include <stdio.h> 
#include <string.h>
#include "../libft.h"
  
int main() 
{ 
    char str[50] = "VinnyBass is the king of SF6."; 
  
    ft_bzero(str + 5, 8*sizeof(char)); 
  
    if (strcmp(str, "Vinny") != 0)
      return 1;
    return 0; 
} 