#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

int test_ft_substr(void) {
    int fail = 0;

    // Test 1: Substring within the bounds of the string
    char const *str1 = "Hello, World!";
    char *sub1 = ft_substr(str1, 7, 5);
    if (strcmp(sub1, "World") != 0) fail = 1;
    free(sub1);

    // Test 2: 'start' index beyond the end of the string
    char *sub2 = ft_substr(str1, 20, 5);
    if (sub2 != NULL) fail = 1;
    free(sub2);

    // Test 3: 'len' more than the length of the string after 'start'
    char *sub3 = ft_substr(str1, 7, 20);
    if (strcmp(sub3, "World!") != 0) fail = 1;
    free(sub3);

    // Test 4: 'len' is zero
    char *sub4 = ft_substr(str1, 7, 0);
    if (sub4 != NULL) fail = 1;
    free(sub4);

    // Test 5: Original string 's' is NULL
    char *sub5 = ft_substr(NULL, 7, 5);
    if (sub5 != NULL) fail = 1;

    return fail;
}

int main(void) {
    if (test_ft_substr() == 0) {
        return 0;
    } else {
        return 1;
    }
}
