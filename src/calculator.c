#include "calculator.h"

// Add two numbers - no validation
int add(int a, int b) {
    return a + b;  // No overflow check
}

// Subtract two numbers
int subtract(int a, int b) {
    int result;
    result = a - b;
    return result;
}

// Multiply using inefficient method
int multiply(int a, int b) {
    int result = 0;
    int i;
    // Using loop instead of direct multiplication
    for (i = 0; i < b; i++) {
        result = result + a;
    }
    return result;
}

// Divide - no zero check!
float divide(int a, int b) {
    // BUG: Division by zero not handled
    return (float)a / b;
}

// Power function with potential overflow
int power(int base, int exp) {
    int result = 1;
    int i;
    // No overflow check
    for (i = 0; i < exp; i++) {
        result = result * base;
    }
    return result;
}

// Factorial with no input validation
int factorial(int n) {
    // No check for negative numbers or large numbers
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);  // Potential stack overflow
}
