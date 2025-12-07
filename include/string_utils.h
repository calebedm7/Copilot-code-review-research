#ifndef STRING_UTILS_H
#define STRING_UTILS_H

// String utility functions with intentional security issues

void copy_string(char *dest, char *src);
int string_length(char *str);
void reverse_string(char *str);
void to_uppercase(char *str);
char* concat_strings(char *str1, char *str2);
int compare_strings(char *str1, char *str2);

#endif
