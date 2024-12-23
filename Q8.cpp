#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void insertAtBeginning(int data) {
    struct node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);
}


void insertAtEnd(int data) {
    struct node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at the end.\n", data);
}

void insertAtPosition(int data, int position) {
    if (position <= 0) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(data);
        return;
    }
    struct node* newNode = createNode(data);
    struct node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, position);
}


void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}


void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    if (temp->next == NULL) { 
        head = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    printf("Deleted %d from the end.\n", temp->data);
    free(temp);
}


void deleteAtPosition(int position) {
    if (position <= 0 || head == NULL) {
        printf("Invalid position or list is empty.\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning();
        return;
    }
    struct node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    printf("Deleted %d from position %d.\n", temp->data, position);
    free(temp);
}


void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("Double Linked List (head to rear): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtPosition(15, 2);
    insertAtEnd(25);
    display();

    deleteAtPosition(2);
    display();

    deleteAtEnd();
    display();

    deleteAtBeginning();
    display();

    return 0;
}
