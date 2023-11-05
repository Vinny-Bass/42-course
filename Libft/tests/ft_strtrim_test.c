#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

// Helper function to compare strings and print result
int test_strtrim(const char *test, const char *set, const char *expected) {
    char *result = ft_strtrim(test, set);
    if (result == NULL && expected == NULL) {
        return 0; // Success: both are NULL
    }
    if (result != NULL && expected != NULL && strcmp(result, expected) == 0) {
        free(result);
        return 0; // Success: strings match
    }
    
    printf("Test failed:\nInput: '%s'\nSet: '%s'\nExpected: '%s'\nGot: '%s'\n",
           test, set, expected, result ? result : "NULL");
    free(result);
    return 1; // Failure
}

int main() {
    int errors = 0;
    
    errors += test_strtrim("  hello  ", " ", "hello");
    errors += test_strtrim("xxxhelloxxx", "x", "hello");
    errors += test_strtrim("hello world", "hd", "ello worl");
    errors += test_strtrim("hello world", "d", "hello worl");
    errors += test_strtrim("test", "xyz", "test"); // No trim should happen
    //errors += test_strtrim("", " ", ""); // Empty string
    errors += test_strtrim("abc", "", "abc"); // Empty set
    errors += test_strtrim("  ", " ", NULL); // String with only set chars

    if (errors == 0) {
        printf("All tests passed!\n");
    } else {
        printf("%d test(s) failed.\n", errors);
    }

    return errors;
}
