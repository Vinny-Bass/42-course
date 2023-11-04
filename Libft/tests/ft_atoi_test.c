#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "../libft.h"

int main() {
    int val;
    char str[30];
    
    // Test with leading whitespace
    strcpy(str, " \t\n\v\f\r98993489");
    val = ft_atoi(str);
    if (val != 98993489) return 1;
    
    // Test with positive sign
    strcpy(str, "+42");
    val = ft_atoi(str);
    if (val != 42) return 1;
    
    // Test with negative sign
    strcpy(str, "-42");
    val = ft_atoi(str);
    if (val != -42) return 1;
    
    // Test with letters and numbers
    strcpy(str, "123vinny");
    val = ft_atoi(str);
    if (val != 123) return 1;
    
    // Test for potential overflow
    strcpy(str, "2147483647"); // INT_MAX
    val = ft_atoi(str);
    if (val != 2147483647) return 1;

    // Test for potential underflow
    strcpy(str, "-2147483648"); // INT_MIN
    val = ft_atoi(str);
    if (val != (-2147483647 - 1)) return 1; // To avoid potential undefined behavior by directly using INT_MIN

    // Test with only a sign
    strcpy(str, "-");
    val = ft_atoi(str);
    if (val != 0) return 1;
    
    strcpy(str, "+");
    val = ft_atoi(str);
    if (val != 0) return 1;
    
    // Test with plus signs
    strcpy(str, "++42");
    val = ft_atoi(str);
    if (val != 0) return 1; // Assuming we consider this invalid
    
    strcpy(str, "--42");
    val = ft_atoi(str);
    if (val != 0) return 1; // Assuming we consider this invalid
    
    // Test with number that includes a decimal point
    strcpy(str, "42.5");
    val = ft_atoi(str);
    if (val != 42) return 1;

    // Test with a large number that would cause overflow
    strcpy(str, "9999999999");
    val = ft_atoi(str);
    if (val != INT_MAX) return 1;

    printf("All tests passed!\n");
    return 0;
}
