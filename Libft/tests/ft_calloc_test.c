#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main()
{
 
    int* ptr;
    int n, i;
 
    n = 5;
    ptr = (int*)ft_calloc(n, sizeof(int));
 
    if (ptr == NULL) {
		return (1);
    } else {
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }

		int toCompare[] = {1,2,3,4,5};
		if (ft_memcmp(ptr, toCompare, n * sizeof(int)) != 0)
			return (1);
    }
 
    return 0;
}
