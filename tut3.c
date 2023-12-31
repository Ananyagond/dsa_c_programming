#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    int ruleNumber;
    char name[50];
    int age;
    struct Student* next;
};

// Function to display the student details
void displayStudents(struct Student* head) {
    printf("\nStudent Details:\n");
    while (head != NULL) {
        printf("Rule Number: %d\n", head->ruleNumber);
        printf("Name: %s\n", head->name);
        printf("Age: %d\n", head->age);
        printf("-----------------\n");
        head = head->next;
    }
    printf("\n");
                
}

// Function to insert a new student record into the linked list
struct Student* insertStudent(struct Student* head, int ruleNumber, char name[], int age) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->ruleNumber = ruleNumber;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = head;
    return newStudent;
}

// Function to delete a student record based on rule number
struct Student* deleteStudent(struct Student* head, int ruleNumber) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    struct Student* temp;
    struct Student* prev = NULL;

    // Traverse the list to find the record to be deleted
    temp = head;
    while (temp != NULL && temp->ruleNumber != ruleNumber) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Record with Rule Number %d not found.\n", ruleNumber);
    } else {
        // Delete the record
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        printf("Record with Rule Number %d deleted successfully.\n", ruleNumber);
    }

    return head;
}

int main() {
    struct Student* head = NULL;
    int choice;
    int ruleNumber;
    char name[50];
    int age;

    do {
        printf("\nOptions:\n");
        printf("1. Display Student Details\n");
        printf("2. Insert New Student Record\n");
        printf("3. Delete Student Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStudents(head);
                break;
            case 2:
                printf("Enter Rule Number: ");
                scanf("%d", &ruleNumber);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                head = insertStudent(head, ruleNumber, name, age);
                break;
            case 3:
                printf("Enter Rule Number to Delete: ");
                scanf("%d", &ruleNumber);
                head = deleteStudent(head, ruleNumber);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free the allocated memory for the linked list
    while (head != NULL) {
        struct Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}