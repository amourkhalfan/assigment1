#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct node {
    int data;
    struct node* next;
};

struct node* head = NULL; // Initialize the head pointer to NULL

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insertion at the beginning
void insertAtBeginning(int data) {
    struct node* newNode = createNode(data);
    if (newNode == NULL) return;

    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}

// Insertion at the end
void insertAtEnd(int data) {
    struct node* newNode = createNode(data);
    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", data);
}

// Insertion at a specific position
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
    if (newNode == NULL) return;

    struct node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, position);
}

// Deletion at the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

// Deletion at the end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) { // Only one node
        printf("Deleted %d from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted %d from the end.\n", temp->data);
    prev->next = NULL;
    free(temp);
}

// Deletion at a specific position
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
    struct node* prev = NULL;

    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted %d from position %d.\n", temp->data, position);
    free(temp);
}

// Display the linked list
void display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("Linked List Elements (head to rear): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
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
