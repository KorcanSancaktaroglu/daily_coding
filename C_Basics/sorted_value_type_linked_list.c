#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
typedef struct value_type {
    int num;
    struct value_type* next;

}value;
value* createNode();
value* insertAtEnd(value* head);
void displayList(value* head);
void sortOfList(value* head);
void freeList(value* head);

int main()
{
    value* head = NULL;
    
    while (1) {
        int choice;
        printf("Enter your num to add ('-1' to finish):"); scanf_s("%d", &choice);
        if (choice == -1) break;
        head = insertAtEnd(head);
    }   printf("=========== List===========\n");
        displayList(head);
        sortOfList(head);
        printf("========Sorted List========\n");
        displayList(head);

        freeList(head);
     printf("\nMemory cleared. Program terminated.\n");
    return 0;
}
value* createNode() {
    int tempNum;
    printf("Enter Your Num:"); scanf_s("%d", &tempNum);
    value* newNode = (value*)malloc(sizeof(value));
    if (!newNode) return NULL;
    newNode->num = tempNum;
    newNode->next = NULL;

    return newNode;


   

}
value* insertAtEnd(value* head) {
    
    value* newNode = createNode();
    if (!head) return newNode;
    value* temp = head;

    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
void displayList(value *head) {
    value* curr = head;
    printf("\nList\n ");
    if (!curr) { printf("List is empty\n"); return; }
    while (curr) {
        printf("Num: %d\n",curr->num);
        curr = curr->next;

    }
    printf("Null\n");

    return;

    

}
//O(n**2)
void sortOfList(value* head) {
    int tempNum;
    if (!head || !head->next) { printf("Error\n");  return; }
    value* i, * j;
    for (i = head; i != NULL; i=i->next) {
        for (j = i->next; j != NULL; j=j->next) {
            if (i->num > j->num)
            {
                tempNum = j->num;
                j->num = i->num;
                i->num = tempNum;

            }
        }
    }

    



}
void freeList(value* head) {
    if (!head) { printf("List is empty"); return; }
    value* temp;
    while (head) {
        temp  = head;
        head = head->next;
        free(temp);

    }


}
