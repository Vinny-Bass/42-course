#include "../libft.h"
#include <stdio.h>
#include <string.h>

void free_split_result(char **result) {
    char **curr = result;
    while (*curr) {
        free(*curr);
        curr++;
    }
    free(result);
}

int compare_string_arrays(char **arr1, const char *const *arr2) {
    for (int i = 0; arr1[i] || arr2[i]; i++) {
        if (arr1[i] == NULL || arr2[i] == NULL)
            return arr1[i] != arr2[i];
        if (strcmp(arr1[i], arr2[i]) != 0)
            return 1;
    }
    return 0;
}

int test_split(const char *input, char delimiter, const char *const *expected) {
    char **result = ft_split(input, delimiter);
    int test_failed = compare_string_arrays(result, expected);
    free_split_result(result);
    return test_failed;
}

int main() {
    int any_test_failed = 0;

    // Test 1: Empty string
    const char *r1[] = {NULL};
    any_test_failed |= test_split("", '-', r1);

    // Test 2: No delimiter present
    const char *r2[] = {"vinny", NULL};
    any_test_failed |= test_split("vinny", '-', r2);

    // Test 3: Single delimiter present
    const char *r3[] = {"vinny", "bass", NULL};
    any_test_failed |= test_split("vinny-bass", '-', r3);

    // Test 4: Delimiter at the beginning
    const char *r4[] = {"hello", NULL};
    any_test_failed |= test_split("-hello", '-', r4);

    // Test 5: Delimiter at the end
    const char *r5[] = {"hello", NULL};
    any_test_failed |= test_split("hello-", '-', r5);

    return any_test_failed;
}
