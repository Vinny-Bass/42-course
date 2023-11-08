#include "../libft.h"

int test_ft_itoa(void) {
    int fail = 0;

    // Test 1: positive number
    char *r1 = ft_itoa(123);
    if (strcmp("123", r1) != 0) fail = 1;
    //free(r1);

    // Test 2: negative number
    char *r2 = ft_itoa(-123);
    if (strcmp("-123", r2) != 0) fail = 1;
    // free(r2);

    // Test 3: zero
    char *r3 = ft_itoa(0);
    if (strcmp("0", r3) != 0) fail = 1;
    free(r3);

    // Test 4: large number > INT_MAX
    char *r4 = ft_itoa(123456789);
    if (strcmp("123456789", r4) != 0) fail = 1;
    free(r4);


    return fail;
}

int main(void) {
    if (test_ft_itoa() == 0) {
        return 0;
    } else {
        return 1;
    }
}