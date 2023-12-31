#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    char data;
    struct Node* next;
};

// Function to display the linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%c -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a new node with the given character
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to separate uppercase and lowercase characters into two linked lists
void separateLists(struct Node* originalList, struct Node** uppercaseList, struct Node** lowercaseList) {
    struct Node* current = originalList;

    while (current != NULL) {
        if (current->data >= 'A' && current->data <= 'Z') {
            // Uppercase character, add to uppercase list
            if (*uppercaseList == NULL) {
                *uppercaseList = createNode(current->data);
            } else {
                struct Node* temp = *uppercaseList;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = createNode(current->data);
            }
        } else if (current->data >= 'a' && current->data <= 'z') {
            // Lowercase character, add to lowercase list
            if (*lowercaseList == NULL) {
                *lowercaseList = createNode(current->data);
            } else {
                struct Node* temp = *lowercaseList;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = createNode(current->data);
            }
        }

        current = current->next;
    }
}

// Function to free the memory allocated for a linked list
void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* originalList = NULL;
    struct Node* uppercaseList = NULL;
    struct Node* lowercaseList = NULL;
    char inputChar;

    // Take user-defined input for the linked list
    printf("Enter characters for the linked list (Enter '0' to end):\n");
    while (1) {
        scanf(" %c", &inputChar);  // Read a character from the user

        if (inputChar == '0') {
            break;  // Exit the loop when '0' is entered
        }

        // Create a new node for the entered character and add it to the original list
        struct Node* newNode = createNode(inputChar);
        newNode->next = originalList;
        originalList = newNode;
    }

    // Display the original linked list
    printf("\nOriginal Linked List:\n");
    displayList(originalList);

    // Separate the characters into uppercase and lowercase lists
    separateLists(originalList, &uppercaseList, &lowercaseList);

    // Display the separated lists
    printf("\nUppercase Linked List:\n");
    displayList(uppercaseList);

    printf("\nLowercase Linked List:\n");
    displayList(lowercaseList);

    // Free the allocated memory for the linked lists
    freeList(originalList);
    freeList(uppercaseList);
    freeList(lowercaseList);

    return 0;
}