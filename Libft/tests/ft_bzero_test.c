#include <stdio.h> 
#include <string.h>
#include "../libft.h"
  
int main() 
{
    int test_failed = 0;

    // Test 1: Zeroing part of a string
    char str1[50] = "VinnyBass is the king of SF6.";
    ft_bzero(str1 + 5, 8*sizeof(char)); 
    if (strcmp(str1, "Vinny") != 0) test_failed++;

    // Test 2: Zeroing an entire array
    char str2[10];
    memset(str2, 'A', sizeof(str2)); // Fill the array with 'A' for testing
    ft_bzero(str2, sizeof(str2));
    for (size_t i = 0; i < sizeof(str2); ++i) {
        if (str2[i] != '\0') test_failed++;
    }

    // Test 3: Zeroing part of an array, check exact position of zeroing
    char str3[10] = "123456789";
    ft_bzero(str3 + 2, 5*sizeof(char));
    if (str3[0] != '1' || str3[1] != '2' || str3[7] != '8' || str3[8] != '9' || str3[2] != '\0') test_failed++;

    // Test 4: Zeroing with a zero-length buffer
    char str4[50] = "Should remain unchanged";
    char str4_copy[50];
    strcpy(str4_copy, str4); // Copy for comparison
    ft_bzero(str4, 0); 
    if (strcmp(str4, str4_copy) != 0) test_failed++;

    // Test 5: Zeroing a large buffer
    char str5[1000];
    memset(str5, 'B', sizeof(str5));
    ft_bzero(str5, sizeof(str5));
    for (size_t i = 0; i < sizeof(str5); ++i) {
        if (str5[i] != '\0') test_failed++;
    }

    return test_failed;
}
