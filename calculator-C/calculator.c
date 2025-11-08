#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b, bool *error);
bool read_double(const char *prompt, double *value);
bool is_valid_operator(char op);

int main() {
    char operator;
    double num1, num2, result;
    bool error = false;
    
    printf("Simple Calculator\n");
    printf("=================\n");
    
    // Read and validate operator
    printf("Enter an operation (+, -, *, /): ");
    if (scanf(" %c", &operator) != 1) {
        fprintf(stderr, "Error: Failed to read operator\n");
        return 1;
    }
    
    if (!is_valid_operator(operator)) {
        fprintf(stderr, "Error: Invalid operator '%c'\n", operator);
        return 1;
    }
    
    // Read and validate first number
    if (!read_double("Enter first number: ", &num1)) {
        fprintf(stderr, "Error: Invalid first number\n");
        return 1;
    }
    
    // Read and validate second number
    if (!read_double("Enter second number: ", &num2)) {
        fprintf(stderr, "Error: Invalid second number\n");
        return 1;
    }
    
    // Perform calculation
    switch(operator) {
        case '+':
            result = add(num1, num2);
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            result = divide(num1, num2, &error);
            if (error) {
                fprintf(stderr, "Error: Division by zero\n");
                return 1;
            }
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            break;
    }
    
    return 0;
}

// Function implementations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b, bool *error) {
    if (b == 0.0) {
        *error = true;
        return 0.0;
    }
    *error = false;
    return a / b;
}

bool read_double(const char *prompt, double *value) {
    printf("%s", prompt);
    if (scanf("%lf", value) != 1) {
        // Clear input buffer on error
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return false;
    }
    return true;
}

bool is_valid_operator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}
