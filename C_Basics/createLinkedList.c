#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct dog_type {
    int ID;
    int age; 
    struct dog_type* next;


}dog;
dog* createList();
int main()
{
    
    
    return 0;


}
dog* createList() {
    dog* head = NULL, * tail = NULL, * newNode;
    int tempID;
    while (1)
    { 
        printf("Enter Dog ID(0 to stop)");
        scanf("%d", &tempID);
        if (!tempID) break;

        newNode = (dog*)malloc(sizeof(dog));
        newNode->ID = tempID;
        printf("Enter Dog Age : ");
        scanf("%d", &newNode->age);
        newNode->next = NULL;


        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            head->next = newNode;
                tail = newNode;

        }





    }
    return head;

}

