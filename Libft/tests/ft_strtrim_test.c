#include "../libft.h"
#include <stdio.h>
#include <string.h>


int test_strtrim(const char *test, const char *set, const char *expected) {
    char *result = ft_strtrim(test, set);
    if (result == NULL && expected == NULL) {
        return 0;
    }
    if (result != NULL && expected != NULL && strcmp(result, expected) == 0) {
        free(result);
        return 0;
    }
    
    printf("Test failed:\nInput: '%s'\nSet: '%s'\nExpected: '%s'\nGot: '%s'\n",
           test, set, expected, result ? result : "NULL");
    free(result);
    return 1;
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

    return errors;
}
