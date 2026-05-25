#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct dog_type {
    int ID;
    int age; 
    struct dog_type* next;


}Dog;
// Function Prototypes
Dog* createNode(int id, int age);
Dog* insertAtEnd(Dog* head, int id, int age);
void displayList(Dog* head);
void searchByID(Dog* head, int searchID);
Dog* deleteByID(Dog* head, int deleteID);
void freeList(Dog* head);
int main()
{
    Dog* head = NULL;
    int choice, id, age;

    printf("--- Welcome to Dog Registry System (Linked List) ---\n");

    // Phase 1: Creation
    while (1) {
        printf("\nEnter Dog ID to add (-1 to finish): ");
        scanf("%d", &id);
        if (id == -1) break;

        printf("Enter Dog Age: ");
        scanf("%d", &age);
        head = insertAtEnd(head, id, age);
    }

    // Phase 2: Operations
    displayList(head);

    // Search Example
    printf("\nEnter an ID to SEARCH: ");
    scanf("%d", &id);
    searchByID(head, id);

    // Delete Example
    printf("\nEnter an ID to DELETE: ");
    scanf("%d", &id);
    head = deleteByID(head, id);

    // Final View
    displayList(head);

    // Phase 3: Memory Cleanup
    freeList(head);
    printf("\nMemory cleared. Program terminated.\n");

    return 0;
}
    
    



Dog* createNode(int id, int age) {
    Dog* newNode = (Dog*)malloc(sizeof(Dog));
    if (!newNode) return NULL;
    newNode->ID = id;
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}
Dog* insertAtEnd(Dog* head, int id, int age) {
    Dog* newNode = createNode(id, age);
    if (!head) return newNode;

    Dog* temp = head;
    while (temp->next) {
        temp = temp->next;

    }
    temp->next = newNode;
    return head;

}
void  displayList(Dog* head) {
    Dog* current = head;
    printf("\n--- Current Dog List ---\n");
    if (!current) printf("List is Empty\n");

    while (current) {
        printf("[ID: %d | Age: %d] -> ", current->ID, current->age);
        current = current->next;

    }
    printf("NULL\n");
}
void searchByID(Dog* head, int searchID) {
    Dog* current = head;
    while (current) {
        if (current->ID == searchID) {
            printf("RESULT: Found Age of Dog %d is %d.\n", searchID, current->age);
            return;
        }
        current = current->next;
    }
    printf("RESULT: ID %d found  not in the list.\n", searchID);

}
Dog* deleteByID(Dog* head, int deleteID) {
    Dog* current = head, * prev = NULL;
    while (current) {
        if (current->ID == deleteID) {
            if (current == head) head = head->next;
            else {
                prev->next = current->next;
            }
            free(current);
            printf("SUCCESS: ID %d has been removed.\n", deleteID);
            return head;
        }
        prev = current;
        current = current->next;
    }
    printf("ERROR: Could not find ID %d to delete.\n", deleteID);
    return head;
}
void freeList(Dog* head) {
    Dog* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}






