#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int num) {
    stack[++top] = num;
}

int pop() {
    return stack[top--];
}

int evaluatePrefix(char* exp) {
    int i, op1, op2;
    for (i = strlen(exp) - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            op1 = pop();
            op2 = pop();
            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[SIZE];
    printf("Enter prefix expression: ");
    scanf("%s", exp);
    printf("Result: %d\n", evaluatePrefix(exp));
    return 0;
}
