#include "../libft.h"

int test_ft_strjoin(void) {
    int fail = 0;

    // Test 1: Normal concatenation
    char const *s1 = "Hello";
    char const *s2 = "World";
    char *result1 = ft_strjoin(s1, s2);
    if (strcmp(result1, "HelloWorld") != 0) fail = 1;
    free(result1);

    // Test 2: Concatenation where the first string is empty
    char const *s3 = "";
    char *result2 = ft_strjoin(s3, s2);
    if (strcmp(result2, "World") != 0) fail = 1;
    free(result2);

    // Test 3: Concatenation where the second string is empty
    char const *s4 = "";
    char *result3 = ft_strjoin(s1, s4);
    if (strcmp(result3, "Hello") != 0) fail = 1;
    free(result3);

    // Test 4: Concatenation where both strings are empty
    char *result4 = ft_strjoin(s3, s4);
	// printf("%s", result4);
    if (strcmp(result4, "") != 0) fail = 1;
    free(result4);

    // Test 5: Concatenation with NULL inputs (if supported)
    char *result5 = ft_strjoin(NULL, s2);
    char *result6 = ft_strjoin(s1, NULL);
    if (result5 != NULL || result6 != NULL) fail = 1;
    free(result5);
    free(result6);

    return fail;
}

int main(void) {
    if (test_ft_strjoin() == 0) {
        return 0;
    } else {
        return 1;
    }
}
