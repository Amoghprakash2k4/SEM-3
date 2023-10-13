#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to check if a character is an operand (a digit)
int isOperand(char c) {
    return (c >= '0' && c <= '9');
}

// Function to determine the precedence of an operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char *infix, char *prefix) {
    char stack[MAX];
    int top = -1;
    int i, j = 0;

    // Reverse the infix expression
    reverseString(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isOperand(current)) {
            prefix[j++] = current;
        } 
        else if (isOperator(current)) {
            while (top >= 0 && precedence(stack[top]) >= precedence(current)) {
                prefix[j++] = stack[top--];
            }
            stack[++top] = current;
        } 
        else if (current == ')') {
            stack[++top] = current;
        } 
        else if (current == '(') {
            while (top >= 0 && stack[top] != ')') {
                prefix[j++] = stack[top--];
            }
       
     if (top >= 0 && stack[top] == ')') {
                top--; // Pop the '('
            }
        }
    }
    while (top >= 0) {
        prefix[j++] = stack[top--];
    }

    prefix[j] = '\0';

    // Reverse the prefix expression to get the final result
    reverseString(prefix);
}

int main() {
    char infix[MAX];
    char prefix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("The prefix expression is: %s\n", prefix);

    return 0;
}
