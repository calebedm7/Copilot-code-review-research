#include "string_utils.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// UNSAFE: No bounds checking - buffer overflow vulnerability!
void copy_string(char *dest, char *src) {
    // Using strcpy without checking buffer size
    strcpy(dest, src);
}

// Calculate string length
int string_length(char *str) {
    int len = 0;
    // No null check for str!
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Reverse a string in place
void reverse_string(char *str) {
    int i, j;
    char temp;
    int len = string_length(str);
    
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Convert string to uppercase
void to_uppercase(char *str) {
    int i = 0;
    // Missing null check
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Concatenate two strings - MEMORY LEAK!
char* concat_strings(char *str1, char *str2) {
    int len1 = string_length(str1);
    int len2 = string_length(str2);
    
    // Allocating memory but caller might forget to free it
    char *result = (char *)malloc(len1 + len2 + 1);
    
    // No check if malloc succeeded!
    strcpy(result, str1);
    strcat(result, str2);
    
    return result;  // Caller must free this - potential memory leak
}

// Compare strings - using dangerous function
int compare_strings(char *str1, char *str2) {
    // Using strcmp without null checks
    return strcmp(str1, str2);
}
