#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Delete a node with given value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head needs to be deleted
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", value);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If not found
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Unlink and delete
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

// Display the linked list
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver code to demonstrate operations
int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertEnd(&head, value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(&head, value);
            break;
        case 3:
            traverseList(head);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
