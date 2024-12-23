#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int num) {
    stack[++top] = num;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* exp) {
    int i, op1, op2;
    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            op2 = pop();
            op1 = pop();
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
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}
