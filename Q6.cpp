#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct queue {
    int que[SIZE];
    int front, rear;
} q;

int isFull() {
    return q.rear == SIZE - 1;
}

int isEmpty() {
    return q.front == -1 || q.front > q.rear;
}

void insert(int item) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d.\n", item);
        return;
    }
    if (q.front == -1) q.front = 0; 
    q.que[++q.rear] = item; 
    printf("Inserted: %d\n", item);
}

void deleteItem() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    }
    printf("Deleted: %d\n", q.que[q.front++]);
    if (q.front > q.rear) q.front = q.rear = -1; 
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue Elements: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.que[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    display();
    deleteItem();
    display();
    return 0;
}
