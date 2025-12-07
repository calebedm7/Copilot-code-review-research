#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include "string_utils.h"

// Global variable - not a best practice
int debug_mode = 1;

// Main function with various issues
int main() {
    printf("=== Code Review Demo Program ===\n\n");
    
    // Test calculator functions
    printf("Calculator Tests:\n");
    printf("5 + 3 = %d\n", add(5, 3));
    printf("10 - 4 = %d\n", subtract(10, 4));
    printf("6 * 7 = %d\n", multiply(6, 7));
    
    // BUG: Division by zero!
    printf("10 / 2 = %.2f\n", divide(10, 2));
    printf("10 / 0 = %.2f\n", divide(10, 0));  // Will cause undefined behavior
    
    printf("2^3 = %d\n", power(2, 3));
    printf("5! = %d\n", factorial(5));
    
    // Test string functions with issues
    printf("\nString Utility Tests:\n");
    
    // Buffer overflow vulnerability!
    char buffer[10];
    char *long_string = "This is a very long string that will overflow the buffer!";
    copy_string(buffer, "Hello");  // OK
    printf("Copied: %s\n", buffer);
    
    // DANGEROUS: This will overflow!
    // copy_string(buffer, long_string);
    
    // Test string length
    char *test_str = "Testing";
    printf("Length of '%s': %d\n", test_str, string_length(test_str));
    
    // Test reverse
    char rev_str[] = "reverse";
    reverse_string(rev_str);
    printf("Reversed 'reverse': %s\n", rev_str);
    
    // Test uppercase
    char upper_str[] = "hello world";
    to_uppercase(upper_str);
    printf("Uppercase: %s\n", upper_str);
    
    // Memory leak - not freeing allocated memory!
    char *concatenated = concat_strings("Hello, ", "World!");
    printf("Concatenated: %s\n", concatenated);
    // Missing free(concatenated) - MEMORY LEAK!
    
    // Compare strings
    if (compare_strings("test", "test") == 0) {
        printf("Strings are equal\n");
    }
    
    // Magic number usage
    int array[5];
    int i;
    for (i = 0; i < 5; i++) {  // Magic number 5
        array[i] = i * 2;
    }
    
    // No return value check
    printf("\nProgram completed\n");
    
    return 0;  // Success
}
