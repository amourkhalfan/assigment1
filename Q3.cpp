#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void infixToPrefix(char* exp) {
    reverseString(exp);
    char* e = exp, x;
    printf("Prefix Expression: ");
    char result[SIZE];
    int k = 0;

    while (*e != '\0') {
        if (isalnum(*e)) {
            result[k++] = *e;
        } else if (*e == ')') {
            push(*e);
        } else if (*e == '(') {
            while ((x = pop()) != ')') {
                result[k++] = x;
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(*e)) {
                result[k++] = pop();
            }
            push(*e);
        }
        e++;
    }
    while (top != -1) {
        result[k++] = pop();
    }
    result[k] = '\0';
    reverseString(result);
    printf("%s\n", result);
}

int main() {
    char exp[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", exp);
    infixToPrefix(exp);
    return 0;
}
