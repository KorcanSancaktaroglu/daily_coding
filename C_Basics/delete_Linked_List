#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct dog_type {
    int ID;
    int age; 
    struct dog_type* next;


}dog;
dog* deleteDog(dog* head,int deleteID);
int main()
{
    
    
    return 0;


}
dog* deleteDog(dog* head, int deleteID) {
    dog* current = head, * previous = NULL;
    while (current) {
        if (current->ID == deleteID) {
            if (current == head) {
                head = head->next;
            }
            else {
                previous->next = current->next;
            }
            free(current);
            printf("ID %d deleted successfully.\n", deleteID);
            return head;

        }
        previous = current;
        current = current->next;
    }
    printf("ID %d not found to delete.\n", deleteID);
    return head;
    
}
   
    


