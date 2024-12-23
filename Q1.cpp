#include <stdio.h>
#define SIZE 100

struct stack {
    int top;
    int s[SIZE];
} st; 

void push(int item) {
    if (st.top >= SIZE - 1) {
        printf("Stack Overflow! Cannot push %d.\n", item);
        return;
    }
    st.s[++st.top] = item; 
    printf("Pushed %d onto the stack.\n", item);
}

int pop() {
    if (st.top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1; 
    }
    return st.s[st.top--];
}

void display() {
    if (st.top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack Elements: ");
    for (int i = 0; i <= st.top; i++) {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Popped: %d\n", pop());
    display();
    return 0;
}
