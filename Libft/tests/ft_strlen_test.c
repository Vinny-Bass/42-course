#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main()
{
    char a[20]="Program";
    char b[20]={'P','r','o','g','r','a','m','\0'};

    if(ft_strlen(a) != 7)
		return 1;
    if(ft_strlen(b) != 7)
		return 1;

    return 0;
}