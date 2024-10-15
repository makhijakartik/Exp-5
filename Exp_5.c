#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;  // Head pointer to the list

// Function to insert a node at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for the new node
    newNode->data = value;  // Assign value to the new node
    newNode->next = head;   // Point the new node to the current head
    head = newNode;  // Make the new node the new head
    printf("%d inserted at the beginning.\n", value);
}

// Function to insert a node at the end
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;  // The new node will be the last, so next is NULL

    if (head == NULL) {
        head = newNode;  // If the list is empty, make the new node the head
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;  // Traverse to the last node
        }
        temp->next = newNode;  // Point the last node to the new node
    }
    printf("%d inserted at the end.\n", value);
}

// Function to delete a node by value
void deleteNode(int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If the list is empty
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // If the head node itself holds the value to be deleted
    if (temp != NULL && temp->data == value) {
        head = temp->next;  // Change the head to the next node
        free(temp);  // Free the old head node
        printf("%d deleted from the list.\n", value);
        return;
    }

    // Traverse the list to find the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not found in the list
    if (temp == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the list.\n", value);
}

// Function to display the linked list
void display() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n*** Singly Linked List Menu ***\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
